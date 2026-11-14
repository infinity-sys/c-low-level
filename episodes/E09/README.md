# E09 · Interview Practice I: Pointers, Layout and Memory

Video: https://youtu.be/bvTC-3yXs3Q

```sh
make run             # the eight questions (q4_str and q8_local crash on purpose)
make answer-warn     # E08 answers: -Wall warns about lines 22 and 23 of bugs.c
make answer-asan     # ASan: stack-buffer-overflow, WRITE of size 13 at bugs.c:19
make answer-vg       # bug 1 fixed (buf[16]); Valgrind finds bugs 2 and 3
```

Linux and WSL2: as is. macOS: Apple clang on arm64 gives the same sizes
for these programs, but the warnings and crash messages differ; for the
exact Debian / GCC 14 output in the video use Docker `--platform linux/amd64`.
Valgrind is optional: skip `make answer-vg` if it is not installed.

## E08 answers (bugs.c, GCC 14.2, Valgrind 3.24, Debian 13, x86-64)

1. Line 19: `strcpy(buf, p)` copies `"hello, world"` (12 characters plus a 0,
   13 bytes) into `char buf[8]`. ASan: stack-buffer-overflow, WRITE of size 13
   at `bugs.c:19`, object `buf` (line 12).
2. Line 22: `printf` of `p` after `free(p)` on line 21. `-Wall`:
   `-Wuse-after-free`. With bug 1 fixed (`bugs_fix1.c`), Valgrind: invalid read
   at line 22, inside a block of size 16 freed at line 21, allocated at line 13.
3. Line 23: `if (n)` reads `n`, which is never set. `-Wall`:
   `-Wmaybe-uninitialized`. Valgrind `--track-origins=yes`: conditional jump on
   an uninitialised value at line 23, created by a stack allocation at line 11.

## The eight questions (real output)

| File | Question | Answer |
|---|---|---|
| q1_sizeof.c | `sizeof a` in main and in `f(int a[10])` | 40 and 8: an array parameter is `int *` (`-Wsizeof-array-argument`) |
| q2_arith.c | bytes moved by `p + 3` | char 3, int 12, double 24, struct rec 36; `sizeof(struct rec)` 12 |
| q3_pad.c | `struct {char; int; char;}` vs `struct {int; char; char;}` | 12 (offsets 0, 4, 8) vs 8 (offsets 0, 4, 5) |
| q4_str.c | `char *s = "hello"` vs `char a[] = "hello"` | sizeof 8 vs 6, strlen 5 and 5; `a[0] = 'H'` works; `s[0] = 'H'` crashes (status 139): literals are read-only |
| q5_endian.c | bytes of `0x11223344` | `44 33 22 11`: little endian |
| q6_index.c | `a[3]`, `*(a + 3)`, `3[a]` | all 40: `a[i]` means `*(a + i)` |
| q7_incr.c | `*p++`, `(*p)++`, `++*p` | x = 10, *p = 20; a = {10, 21, 30}; y = 22, p - a = 1 |
| q8_local.c | returning `&n` of a local | `-Wreturn-local-addr`; p = (nil); `*p` crashes (status 139) |

## Your turn: mini quiz

1. `sizeof` of `struct { char a; double b; char c; }` on x86-64?
2. For `short s[5]`: `&s[4] - &s[0]`, and how many bytes apart?
3. `unsigned int x = 0x01020304;` on a little-endian machine, what is byte 1 of x?

Work them out by hand, then check with a small program. Solutions at the start of E10.
