# E04 · Pointers for Real: arithmetic, decay, GDB memory, aliasing

Video: https://youtu.be/LOarYWS-cXU

```sh
make run       # arith.c and decay.c with ASLR off
make asm       # alias.c at -O2: alias.s
make gdb       # mem.c in GDB: x/4dw nums, x/8xb nums, x/s msg
make solution  # the E03 exercise: gcc -c place.c && nm place.o
```

Stack addresses depend on your environment (even the length of your
environment variables), so yours may differ from the video. The distances
between them do not.

## E03 solution (real output, GCC 14, Debian 13)

```
$ gcc -c place.c && nm place.o
0000000000000000 D a
0000000000000000 B b
0000000000000004 b c
0000000000000000 R d
0000000000000000 D e
0000000000000004 d f.0
                 U free
0000000000000000 T main
                 U malloc
```

| name | region |
|---|---|
| a | data (D) |
| b | bss (B) |
| c | bss (b, static) |
| d | rodata (R) |
| e | the pointer is in data; the string it points to is in rodata |
| f | data (d, renamed f.0) |
| g | stack (a local) |
| h | the pointer is on the stack; what it points to is on the heap |

In GDB, `print &g` gave `0x7fffffffe15c` (stack) and `print h` gave
`0x5555555592a0` (heap).

## What the runs showed

* `p + 1` moves by `sizeof *p`: 1 for char, 4 for int, 8 for double, 12 for a 3-int struct.
* Pointer subtraction counts elements: `(i + 3) - i` is 3, but 12 bytes.
* `sizeof arr` is 40 in `main` and 8 in `show`: the array decays to a pointer.
* `arr + 1` moves 4 bytes; `&arr + 1` moves 40.
* `arr[2]`, `*(arr + 2)` and `2[arr]` are the same thing.
* x86-64 is little-endian: 1 is stored as `01 00 00 00`.
* At -O2, `same(int *a, int *b)` reloads `*a`; `other(int *a, float *b)` does not (strict aliasing); `restrict` promises no aliasing.

## Your turn

`p3.c`: predict how many bytes `p + 3` moves for a `char *`, an `int *` and a
`struct rec *`. Then uncomment the three printf lines and check. Answers at the
start of E05.
