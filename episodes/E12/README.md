# E12 · Strict Aliasing, restrict and Type Punning

Video: https://youtu.be/-Kptz5LUGzg

```sh
make answers    # E11 answers: value and type of the six expressions (_Generic)
make alias      # the strict aliasing bug: 0 at -O0, 1 at -O2, 0 with -fno-strict-aliasing
make alias-asm  # -O2 returns the constant 1: the read of *i is gone
make pun        # cast (one -Wstrict-aliasing warning), memcpy and union: all 0x3f800000
make pun-asm    # all three compile to movd eax,xmm0
make upd-asm    # restrict: *x is loaded once instead of twice
make sum        # restrict speed test at -O2 and -O3
```

Linux and WSL2: as is. Clang 19 (tested) works with `CC=clang` and gives the same alias.c results.
macOS: Apple clang gives the same values, but the objdump targets show arm64 code; for the exact
x86-64 output in the video use Docker `--platform linux/amd64`. Timings depend on your machine.

Measured environment (versions.txt): Debian 13 (trixie), x86-64, GCC 14.2.0 (Debian 14.2.0-19), Clang 19.1.7.

## E11 answers (answers.c)

| # | Expression | Type | Value | Why |
|---|---|---|---|---|
| 1 | `'A' + 1` | int | 66 | a character constant has type int in C |
| 2 | `(unsigned char)200 + 100` | int | 300 | promotion to int |
| 3 | `10u - 20` | unsigned int | 4294967286 | 20 becomes unsigned; wraps modulo 2^32 |
| 4 | `-1L < 1u` | int | 1 | long (8 bytes) holds every unsigned int, so 1u becomes long |
| 5 | `7 / 2 * 2.0` | double | 6.0 | 7 / 2 is int division (3) first |
| 6 | `sizeof('A')` | size_t (unsigned long) | 4 | 'A' is an int |

## What the episode shows (real output, GCC 14.2.0)

| File | Result |
|---|---|
| alias.c | `store(&x, (float *)&x)` returns 0 at -O0, 1 at -O2, 0 at -O2 -fno-strict-aliasing |
| alias.c (-O2 objdump) | `mov [rdi],1` / `mov eax,1` / `mov [rsi],0` / `ret`: no read of `*i` |
| pun.c (-O2 -Wall) | one `-Wstrict-aliasing` warning (line 6); cast, memcpy, union all print `0x3f800000` |
| pun.c (-O2 objdump) | all three are `movd eax,xmm0` / `ret` |
| upd.c (-O2 objdump) | `upd` loads `*x` twice; `upd_r` (restrict) once |
| sum.c | -O2: both 0.21 s; -O3: `sum` 0.210 s, `sum_r` (restrict) 0.051 s on the recording machine |

## Your turn: rewrite the casts safely (solutions in E13)

Rewrite both functions with `memcpy`, so that they have no undefined behavior, then compare
`objdump` at `-O2 -Wall`:

```c
uint64_t get_bits(double d)              { return *(uint64_t *)&d; }
uint16_t read_u16(const unsigned char *p) { return *(uint16_t *)(p + 1); }
```

Bonus: `read_u16` has a second problem besides aliasing. What is it?
