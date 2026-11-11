# E08 · Memory Bugs and the Tools That Catch Them

Video: https://youtu.be/KPGRQ37W9Io

```sh
make usage           # gcc -fstack-usage: work() is 480 bytes static
make run             # ./frame_est  prints  7 3.5 A
make overflow        # warning, then a crash (status 139)
make asan-overflow   # ASan: stack-buffer-overflow, WRITE 17
make asan-uaf        # ASan: heap-use-after-free
make asan-dfree      # ASan: double-free
make asan-leak       # LeakSanitizer: 64 bytes in 1 object
make vg-leak         # Valgrind: 64 bytes definitely lost
make ubsan-uninit    # UBSan does not report this uninit read
make vg-uninit       # Valgrind: uninit at line 6, created at line 4
make exercise        # bugs.c: find three memory bugs (answers in E09)
```

Linux and WSL2: as is. macOS: Apple clang builds the files, but
AddressSanitizer and Valgrind reports differ; for the Debian / GCC 14
numbers in the video use Docker `--platform linux/amd64`. Valgrind is
optional: skip `make vg-*` if it is not installed.

## E07 answer (real output, GCC 14, Debian 13, x86-64, -O0)

`gcc -fstack-usage frame_est.c` reports `work 480 static` and `main 16 static`.

The locals in `work()` sum to 432 bytes: `int a[100]` 400, `double d` 8,
`char name[20]` 20, and the stored parameter `n` 4. That is not 480.

The prologue, from objdump: `push rbp` (8) and `sub rsp, 0x1d0` (464).
The lowest local sits at `rbp-0x1c4` = 452, rounded up to a 16-byte
multiple. Add the return address (8): 8 + 464 + 8 = 480. `./frame_est`
prints `7 3.5 A`.

## What the runs showed (GCC 14.2, Valgrind 3.24, Debian 13)

* `overflow.c`: `strcpy` of 17 bytes (16 characters plus a 0) into
  `buf[8]`. GCC warns `-Wstringop-overflow`. `./overflow`: Segmentation
  fault, status 139. ASan: stack-buffer-overflow, WRITE of size 17 at
  `overflow.c:8`, object `buf` at line 6.
* `uaf.c`: without ASan, the program prints garbage (not `"hello"`) and
  exits 0. ASan: heap-use-after-free, READ at `uaf.c:13`, freed at line
  11, allocated at line 7.
* `dfree.c`: ASan attempting double-free at line 11, prior free at line
  10, allocated at line 6.
* `leak.c`: LeakSanitizer, 64 bytes in 1 object at `leak.c:6`. Valgrind
  `--leak-check=full`: 1 alloc, 0 frees, 64 bytes definitely lost at
  line 6.
* `uninit.c`: no tool: `x is not zero: 32764`, status 0. ASan: `x is
  zero`, no error. UBSan: `x is not zero: 779647075`, no error. Valgrind
  `--track-origins=yes`: conditional jump on an uninitialised value at
  `uninit.c:6`, created at line 4, 7 errors from 5 contexts.

## Your turn

`bugs.c` has three memory bugs. Find them with AddressSanitizer and
Valgrind (`make asan-bugs`, `make vg-bugs`). For each bug, write the
kind, the line, and the tool that reported it. Do not fix them yet.
Answers at the start of E09.
