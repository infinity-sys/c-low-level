# E05 · Structs, Alignment and Padding

Video: VIDEO_LINK_PLACEHOLDER

```sh
make run       # every program from the video
make ptype     # GDB's ptype /o: offsets, holes and padding
make asm       # packed.c at -O2: the misaligned load
make exercise  # six.c: 40 bytes before you start
```

## E04 solution (real output, GCC 14, Debian 13)

`p3_sol.c` is `p3.c` with the printf lines uncommented, plus a sizeof line.

```
$ ./p3_sol
3
12
48
sizeof = 16
```

`char` moves 3 bytes, `int` 12, and `struct rec` 48: `int + char + double`
is 13 bytes, but `sizeof(struct rec)` is 16, because of padding.

## What the runs showed

* Every type has an alignment: char 1, short 2, int 4, long, double and pointers 8 (x86-64 and arm64).
* `struct bad {char a; double b; char c; int d;}`: offsets 0 8 16 20, size 24 (7-byte hole, 3-byte hole).
* `struct good {double b; int d; char a; char c;}`: offsets 0 8 12 13, size 16 (2 bytes of tail padding).
* Tail padding keeps every element of an array aligned.
* `__attribute__((packed))` gives size 9 and alignment 1, and a misaligned load: `movsd xmm0, QWORD PTR 1[rdi]`.
* GCC 14, clang 19 and Apple clang 17 on arm64 give the same layouts: this is the ABI, not a compiler choice.

## Your turn

`six.c` has six fields and is 40 bytes. Reorder the fields so the struct is as
small as possible: find the holes, predict the new size, and check with
`sizeof`, `offsetof` or `ptype /o`. Bonus: what is the minimum, and why can't
it go lower? Answers at the start of E06.
