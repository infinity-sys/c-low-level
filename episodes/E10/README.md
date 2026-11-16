# E10 · Undefined Behavior: Why the Compiler Assumes You Never Do It

Video: VIDEO_LINK_PLACEHOLDER

```sh
make quiz && ./quiz   # E09 quiz solutions
make ovf-run          # x + 1 < x: clang -O0 prints 1, clang -O2 prints 0, gcc -O0 prints 0
make ovf-asm          # the listings: add/cmp/setl at clang -O0, xor eax,eax at -O2
make fix              # x == INT_MAX at -O2, -fwrapv, and -fsanitize=undefined
make null-asm         # the null check after *p: kept at -O0, deleted at -O2
make kinds            # unspecified order, implementation-defined results
```

Linux and WSL2: as is (Clang is optional; the clang lines are skipped if it is missing).
macOS: Apple clang behaves like Clang here, but the listings are arm64; for the
exact x86-64 output in the video use Docker `--platform linux/amd64`.

## E09 quiz solutions (quiz.c, GCC 14.2, Debian 13, x86-64)

1. `sizeof(struct { char a; double b; char c; })` = 24: 1 + 7 padding + 8 + 1 + 7 padding.
2. `short s[5]`: `&s[4] - &s[0]` = 4 (elements); the bytes are 8 apart.
3. `0x01020304` on a little-endian machine: byte 1 is `0x03` (bytes 04 03 02 01).

## What the episode shows (real output, GCC 14.2.0, Clang 19.1.7)

| File | Build | Result |
|---|---|---|
| ovf.c | clang -O0 / clang -O2 / gcc -O0 | `will_overflow(x) = 1` / `0` / `0` for x = INT_MAX |
| ovf.c | objdump | clang -O0: `add eax,0x1`, `cmp`, `setl`; clang -O2: `xor eax,eax; ret`; gcc -O0: `mov eax,0x0` |
| ovf.c | gcc -Wall -Wextra -O2 | no warnings |
| ovf_fix.c | gcc -O2 | `x == INT_MAX`: prints 1 |
| ovf.c | gcc -O2 -fwrapv | prints 1 |
| ovf.c | gcc -fsanitize=undefined | `ovf.c:7:14: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type 'int'` |
| null.c | gcc -O0 / -O2 | the check `cmp ...,0x0; jne` is kept / deleted (`mov eax,DWORD PTR [rdi]; ret`) |
| null.c | gcc -O2 -fno-delete-null-pointer-checks | `test rdi,rdi; je` comes back |
| kinds.c | gcc -Wall -Wextra | f runs, g runs, s = 3; `-7 >> 1` = -4; `sizeof(long)` = 8; char is signed |

## Your turn: classify 6 snippets (solutions in E11)

Undefined, unspecified, implementation-defined, or defined?

1. `int a[4]; a[4] = 1;`
2. `INT_MAX + 1` in `int`
3. `UINT_MAX + 1u` in `unsigned int`
4. `f() + g()` when both functions print
5. `-1 >> 1`
6. `sizeof(long)`

Check the undefined ones with `-fsanitize=undefined`.
