# E11 · Integer Promotions, Conversions and Overflow

Video: https://youtu.be/rEV6HqBGMcU

```sh
make snippets   # E10 answers: the six snippets, with -fsanitize=bounds,signed-integer-overflow
make promo      # integer promotion: unsigned char 200 + 100 is 300, not 44
make cmp        # the trap: -1 < 1u is false
make lt-asm     # the same cmp, then setl (signed) or setb (unsigned)
make mul        # uint16_t 65535 * 65535 overflows int; UBSan reports it
make warn       # -Wall -Wextra (-Wsign-compare) and -Wconversion
make safe       # sign check first, and C23 ckd_add / ckd_mul (-std=c23)
```

Linux and WSL2: as is (`make safe` needs GCC 14 or newer for `-std=c23` and `<stdckdint.h>`;
Clang 19 (tested) works with `CC=clang`).
macOS: Apple clang gives the same values, but `make lt-asm` shows arm64 code; for the exact
x86-64 output in the video use Docker `--platform linux/amd64`.

Measured environment (versions.txt): Debian 13 (trixie), x86-64, GCC 14.2.0 (Debian 14.2.0-19), Clang 19.1.7.

## E10 answers (snippets.c)

| # | Snippet | Kind | Real run |
|---|---|---|---|
| 1 | `int a[4]; a[4] = 1;` | undefined | UBSan: `index 4 out of bounds for type 'int [4]'` |
| 2 | `INT_MAX + 1` in `int` | undefined | UBSan: `signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'` |
| 3 | `UINT_MAX + 1u` | defined (wraps) | `0` |
| 4 | `f() + g()`, both print | unspecified order | `f runs`, `g runs`, `3` |
| 5 | `-1 >> 1` | implementation-defined | `-1` (GCC copies the sign bit) |
| 6 | `sizeof(long)` | implementation-defined | `8` |

## What the episode shows (real output, GCC 14.2.0)

| File | Result |
|---|---|
| promo.c | `a + b = 300`, `sizeof(a + b) = 4`, `c = 44`, `x + 1 = 65536`, `sizeof(ch + 0) = 4` |
| cmp.c | `i < u : 0`, `(unsigned)i = 4294967295`, `l < u : 1`, `i < sizeof(int) : 0`, `-1 < 1u : 0` |
| lt.c (-O2) | `lt_signed`: `cmp edi,esi` / `setl al`; `lt_mixed`: `cmp edi,esi` / `setb al` |
| mul.c | `bad = good = 4294836225`; UBSan: `mul.c:7:22: signed integer overflow: 65535 * 65535 cannot be represented in type 'int'` |
| cmp.c, -Wall -Wextra | 3 x `-Wsign-compare` (lines 7, 11, 12) |
| conv.c | -Wall -Wextra: no warnings; -Wconversion: lines 3 and 4 (`-Wconversion`, `-Wsign-conversion`); line 7 gets no warning |
| safe.c (-std=c23) | `less(-1, 1u) = 1`; `ckd_add: overflow, r not usable`; `ckd_mul: r = 1000000` |

## Your turn: predict 6 expressions (solutions in E12)

Give the value and the type of each one:

1. `'A' + 1`
2. `(unsigned char)200 + 100`
3. `10u - 20`
4. `-1L < 1u`
5. `7 / 2 * 2.0`
6. `sizeof('A')`
