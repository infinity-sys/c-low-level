# E13 · volatile, const and What the Optimizer May Do

Video: VIDEO_LINK_PLACEHOLDER

```sh
make answers        # E12 answers: cast vs memcpy, one -Wstrict-aliasing warning, same values
make answers-asm    # cast and memcpy versions compile to the same movq / movzx
make answers-ubsan  # the bonus: clang -fsanitize=alignment reports the misaligned load (line 14)
make spin           # the as-if rule: delay takes 0.000 s at -O2, delay_v (volatile) still runs
make spin-asm       # delay is a single ret; delay_v loads and stores i every round
make flag           # plain int flag: -O2 hangs (timeout exit 124); -DFIXED (volatile sig_atomic_t) works
make flag-asm       # -O2 reads done once and jumps to itself; FIXED reloads it every pass
make race           # two threads: the volatile counter loses updates, the _Atomic one is 2000000
make race-asm       # v++ is load/add/store, a++ is one lock add
make const          # twice(&x, &x) = 5, use_limit() = 20; -DBAD is a compile error
make const-asm      # two loads of *p; use_limit folds to mov eax,0x14
```

Linux and WSL2: as is (race.c needs no -pthread with glibc 2.34 or later; add it on older systems).
`answers-ubsan` needs Clang (GCC 14's -fsanitize=alignment did not report this load in our test).
macOS: Apple clang gives the same values, but objdump shows arm64 code; for the exact x86-64 output
in the video use Docker `--platform linux/amd64`. Timings and the volatile race totals depend on your machine
and change from run to run.

Measured environment (versions.txt): Debian 13 (trixie), x86-64, GCC 14.2.0 (Debian 14.2.0-19), Clang 19.1.7.

## E12 answers (answers.c)

```c
uint64_t get_bits(double d) {
    uint64_t u;
    memcpy(&u, &d, sizeof u);
    return u;
}

uint16_t read_u16(const unsigned char *p) {
    uint16_t v;
    memcpy(&v, p + 1, sizeof v);
    return v;
}
```

| Function | -O2 machine code | Notes |
|---|---|---|
| `get_bits_cast` / `get_bits` | `movq rax,xmm0` / `ret` (both) | only the cast gets `-Wstrict-aliasing` |
| `read_u16_cast` / `read_u16` | `movzx eax,WORD PTR [rdi+0x1]` / `ret` (both) | output 0x3322 (little-endian) |

Bonus: `p + 1` is an odd address and `uint16_t` needs 2-byte alignment, so the cast is also a
misaligned access (undefined behavior). x86 tolerates it in hardware; other processors may trap.
`memcpy` copies bytes and has no alignment rule.

## What the episode shows (real output, GCC 14.2.0)

| File | Result |
|---|---|
| spin.c | -O0: delay 0.043 s, delay_v 0.145 s; -O2: delay 0.000 s, delay_v 0.165 s (recording machine) |
| spin.c (-O2 objdump) | `delay` is a single `ret`; `delay_v` keeps the load/add/store of `i` |
| flag.c | -O0 prints done (exit 0); -O2 hangs (timeout exit 124); -O2 -DFIXED prints done (exit 0) |
| flag.c (-O2 objdump) | plain int: one load, then `jmp` to itself; volatile: `je` back to the load |
| race.c | volatile 1791252 / 1166092 / 1508018 in three runs; atomic 2000000 every time |
| race.c (-O2 objdump) | `v++`: mov / add / mov; `a++`: `lock add` |
| const.c | `twice(&x, &x)` = 5, `use_limit()` = 20; `-DBAD`: error: assignment of read-only location '*p' |
| const.c (-O2 objdump) | `twice` loads `*p` twice; `use_limit` is `mov eax,0x14` |

## Your turn: volatile, _Atomic or const? (solutions in E14)

1. A status register of a serial port, at a fixed address, read in a loop.
2. A `bool stop`, set by one thread and read by another.
3. A tick counter that a timer interrupt adds to on a microcontroller, read by main.
4. A lookup table of 256 values that never changes.

Give the reason for each.
