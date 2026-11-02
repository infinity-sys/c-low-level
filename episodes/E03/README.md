# E03 · The Memory Map of a Process: text, data, bss, heap, stack

Video: VIDEO_LINK_PLACEHOLDER

```sh
make run       # layout.c: the address of every kind of variable (ASLR off)
make sections  # size + nm: T, R, D, d, B, b
make bss       # 4 MB of zeros: 15856 bytes on disk vs 4015880
make map       # /proc/self/maps, read by the process itself
make grow-run  # stack grows down 48 bytes per call, heap grows up
make aslr      # two normal runs: only the base moves
```

## E02 solution (real output, GCC 14, Debian 13)

| file | gcc -E | gcc -c | link | printed by |
|---|---|---|---|---|
| broken1.c | fails: `config.h: No such file or directory` | · | · | cc1, preprocessing |
| broken2.c | ok | fails: `expected ',' or ';' before 'printf'` (line 6, bug on line 5) | · | cc1, compiler |
| broken3.c | ok | ok | fails: ``undefined reference to `checksum'`` | ld, via collect2 |

The assembler only reads what the compiler wrote, so in practice it does not fail.

## Real addresses (gcc -g, `setarch -R ./layout`)

| name | address | section |
|---|---|---|
| main | 0x555555555159 | text (T) |
| limit | 0x555555556004 | rodata (R) |
| "hello" | 0x555555556008 | rodata |
| counter | 0x555555558028 | data (D) |
| seen | 0x55555555802c | data (d, `seen.0`) |
| zeroed | 0x555555558034 | bss (B) |
| calls | 0x555555558038 | bss (b) |
| heap | 0x5555555592a0 | heap |
| local | 0x7fffffffe1bc | stack |

On macOS (Apple clang 17, arm64) `zeroed` and `calls` come out swapped: never rely on the order of separate globals.

## Your turn

`place.c` has 8 declarations, `a` to `h`. Write the region of each (text, rodata, data, bss, heap, stack; for `e` and `h`, both the pointer and what it points to). Prove it with `gcc -c place.c && nm place.o`, and for `g` and `h` print addresses with `%p` and compare with `/proc/self/maps`. Answers at the start of E04.
