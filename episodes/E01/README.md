# E01 · Who This Course Is For: C as a Portable Assembler, and Your Roadmap

Video: VIDEO_LINK_PLACEHOLDER

| File | What it shows |
|---|---|
| `add.c` | one function: 9 instructions at gcc -O0, 2 at -O2 |
| `sum.c` | a loop: gcc -O2 keeps a 23-instruction loop, clang -O2 swaps it for a closed-form formula, with no loop |
| `ub_loop.c` | signed overflow: three different behaviors from one source; UBSan finds it at 7:38, `-fwrapv` defines it (count = 48) |
| `asif.c` | the as-if rule: `plain` folds to `mov eax,0x2`, `volatile` `keep` keeps all 3 accesses at `[rsp-0x4]` |
| `sum_main.c` | links with `sum.c`: every gcc/clang -O0/-O2 build prints 15 and 2147450880 |
| `addl.c` | `long` instead of `int`: `lea rax,[rdi+rsi*1]` on x86-64, `add x0, x1, x0` on arm64 |

```sh
make add      # objdump at -O0 and -O2
make sum      # CC=clang make sum to see the closed form
make ub       # timeout 3 stops the infinite loop at -O2
make arm64    # clang for aarch64-linux-gnu
make asif     # volatile vs plain at -O2
make run      # CC=clang make run as well
make addl     # the long version of add
make fix      # UBSan report, then -fwrapv
```

Recorded on Debian 13 (Linux x86-64), GCC 14.2.0, clang 19.1.7, binutils 2.44, and Apple clang 17 on an Apple silicon Mac.

## Your turn

Predict `sizeof` of `char`, `short`, `int`, `long`, `void *` and `long double` on x86-64 Linux and on arm64. Then print each with `%zu` and check. The solution is in `../E02/e01-solution/` and at the start of E02.
