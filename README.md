# C Programming For Low Level Developers

Code for the advanced YouTube course by Infinity Systems.
Playlist: PLAYLIST_LINK_PLACEHOLDER · Repository: https://github.com/infinity-sys/c-low-level

This course does not teach `printf` and `for` loops. It teaches what C really does: what the compiler turns your code into, where every byte lives, and what the machine runs. Targets: GCC and clang on x86-64 Linux, with arm64 (AAPCS64) notes.

## Episodes

| # | Title | Folder |
|---|---|---|
| E01 | Who This Course Is For: C as a Portable Assembler, and Your Roadmap | [episodes/E01](episodes/E01) |
| E02 | From Source to Executable: Preprocessor, Compiler, Assembler, Linker | [episodes/E02](episodes/E02) |
| E03 | The Memory Map of a Process: text, data, bss, heap, stack | [episodes/E03](episodes/E03) |
| E04 | Pointers for Real: addresses, arithmetic, decay, aliasing | [episodes/E04](episodes/E04) |
| E05 | Structs, Alignment and Padding | [episodes/E05](episodes/E05) |

## Setup

- Linux (Debian, Ubuntu): `sudo apt install gcc clang binutils make gdb`
- Windows: `wsl --install`, then the same `apt` command inside Ubuntu
- macOS: `xcode-select --install` (Apple clang, Mach-O arm64)
- Docker, the same Linux x86-64 toolchain everywhere:

```sh
docker build -t clow-dev .
docker run --rm -it -v "$PWD":/work clow-dev
```

## License

MIT, see [LICENSE](LICENSE).
