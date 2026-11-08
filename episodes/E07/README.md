# E07 · The Stack in C: Frames, Calling and Recursion Depth

Video: VIDEO_LINK_PLACEHOLDER

```sh
make run             # pow2_sol, frames (setarch -R), vla 1000
make gdb             # GDB: bt, &z in c, frame 1, &y in b
make usage           # gcc -fstack-usage: the frame size of dive()
make depth           # recursion until the stack runs out (crashes on purpose)
make crash           # a 100,000,000-byte VLA (crashes on purpose)
make exercise        # frame_est.c: the function you will estimate
```

Linux and WSL2: as is. macOS: Apple clang builds every file natively, but the
addresses, frame sizes and default stack limit differ; for the x86-64 numbers
in the video use Docker `--platform linux/amd64`.

## E06 solution (real output, GCC 14, Debian 13)

```c
int is_power_of_two(unsigned v)
{
    return v != 0 && (v & (v - 1)) == 0;
}
```

The seven test values give the same results as the loop version
(0, 1, 2, 3, 64, 96, 1024 -> 0, 1, 1, 0, 1, 0, 1). `0 & (0 - 1)` is 0:
for an unsigned 0, `0 - 1` wraps to all ones and `0 & anything` is 0, so
the second test alone would call 0 a power of two. `v != 0` rules it out,
and `&&` stops early, so the `&` is never computed for 0.

## What the runs showed (GCC 14, x86-64, ulimit -s 8192)

* `frames.c` with `setarch -R`: `&x` in main `0x7fffffffe06c`, `&y` in b `...e04c`, `&z` in c `...e02c`: each frame is 0x20 = 32 bytes lower. The stack grows down.
* A small frame at -O0: return address 8 + saved RBP 8 + locals rounded to 16 = 32 bytes.
* GDB `bt` in `c()`: `#0 c`, `#1 b` (line 13), `#2 main` (line 20); `&y - &z = 0x20`.
* `gcc -fstack-usage depth.c`: `dive 1040 static`; the first two `pad` addresses differ by 0x410 = 1040.
* `depth`: Segmentation fault (status 139) after 8000 calls and before 9000 (8 MB / 1040 = 8066). With `ulimit -s 16384`: 16000.
* `./vla 1000` works; `./vla 100000000`: Segmentation fault, status 139, with no error to check.

## Your turn

`frame_est.c` has a function `work()` with `int a[100]`, `double d` and
`char name[20]`. Estimate its frame size by hand (remember the rounding to 16),
then check with `make check-exercise` (`gcc -fstack-usage`) and explain any
difference. Answer at the start of E08.
