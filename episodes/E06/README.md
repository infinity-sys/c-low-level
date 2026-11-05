# E06 · Endianness, Bit Manipulation and Bit Fields

Video: https://youtu.be/U-pL7vA0g3o

```sh
make run       # every program from the video
make gdb       # GDB: x/4xb vs x/1xw on the same int
make asm       # swap32 -> bswap, __builtin_popcount -> popcnt
make exercise  # pow2.c: the loop version you will rewrite
```

Linux and WSL2: as is. macOS: Apple clang runs every file natively (arm64 is
little endian too); for the ELF/x86-64 assembly use Docker `--platform linux/amd64`.

## E05 solution (real output, GCC 14, Debian 13)

`six_sol.c` keeps the original `struct six` and adds `struct six_sorted`,
the same fields sorted by alignment, largest first.

```
$ ./six_sol
six        = 40
six_sorted = 24
```

The original has 16 bytes of holes (7 after `flag`, 2 after `port`, 7 after
`kind`). 24 is the minimum: the fields add up to 8 + 8 + 4 + 2 + 1 + 1 = 24,
the sorted struct has no holes, and 24 is already a multiple of 8.

## What the runs showed

* `0x0A0B0C0D` is stored as `0D 0C 0B 0A`: x86-64 is little endian (low byte at the low address).
* GDB `x/4xb &x` shows `0x0d 0x0c 0x0b 0x0a`; `x/1xw &x` shows `0x0a0b0c0d`.
* `detect.c`: little endian at run time and with `__BYTE_ORDER__`.
* `swap32`, `__builtin_bswap32` and `htonl` all give `0x0D0C0B0A`; `ntohl` undoes `htonl`.
* `gcc -O2` compiles the shift-and-mask `swap32` to one `bswap` instruction.
* `fwrite` writes host order (`xxd`: `0d0c 0b0a`); `read_be32` builds `0x0A0B0C0D` from big-endian bytes on any host.
* Masks: `|` sets, `& ~` clears, `^` toggles, `>> n & 1` tests.
* `v &= v - 1` clears the lowest 1 bit; popcount of 0, 1, 0x29, 0xFF, 0xFFFFFFFF = 0, 1, 3, 8, 32; `-O2 -mpopcnt` gives one `popcnt`.
* `struct flags {ready:1; mode:3; level:4;}`: sizeof 4, byte 0 = `0x9B` with GCC on x86-64; storing 9 in `mode` gives 1 (GCC warns). Bit-field layout is implementation-defined.

## Your turn

`pow2.c` has `is_power_of_two` with a `while` loop. Rewrite it with no loop
(no `while`, no `for`, no recursion). Hint: what does `v & (v - 1)` do to a
number with exactly one bit set? Check the seven test values, and explain why
0 needs special care. Answers at the start of E07.
