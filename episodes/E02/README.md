# E02 · From Source to Executable: Preprocessor, Compiler, Assembler, Linker

Video: VIDEO_LINK_PLACEHOLDER

```sh
make stages   # -E, -S, -c, link: stop after each stage
make phases   # clang -ccc-print-phases
make temps    # -save-temps keeps hello.i, hello.s, hello.o
make sizes    # the E01 exercise solution
```

## E01 solution (real output, 31 Oct 2026)

| type | x86-64 Linux | arm64 Linux | arm64 macOS | x86-64 Windows |
|---|---|---|---|---|
| char | 1 | 1 | 1 | 1 |
| short | 2 | 2 | 2 | 2 |
| int | 4 | 4 | 4 | 4 |
| long | 8 | 8 | 8 | 4 |
| void * | 8 | 8 | 8 | 8 |
| long double | 16 | 16 | 8 | 8 |

x86-64 Linux and macOS were run for real. For all four targets, `long` and `long double` come from `clang --target=... -dM -E -x c /dev/null` (`__SIZEOF_LONG__`, `__SIZEOF_LONG_DOUBLE__`).

## More from the episode

| Command | What it shows |
|---|---|
| `make macro` | `macro.c`: SQ(1 + 2) = 5, SQP(1 + 2) = 9, and the text after `-E` |
| `make headers` | `gcc -H`: one `#include <stdio.h>` opens 31 headers |
| `make builtin` | `printf("...\n")` becomes `call puts` even at -O0; `-fno-builtin` keeps printf |
| `make static` | 15952 vs 758448 bytes, `ldd`, entry 0x1070 = `_start`, main at 0x1050 |

The relocation by hand: S + A - P = 0x2004 - 4 - 0x1057 = 0xfa9.

## Your turn

`broken1.c`, `broken2.c` and `broken3.c` each fail at a different stage. Predict which one, then prove it with `gcc -E`, `gcc -c` and a full link, and note which program printed the error. Answers at the start of E03.
