# E02: stop the build after each stage.
CC ?= gcc

stages:
	$(CC) -E hello.c -o hello.i && wc -l hello.c hello.i
	$(CC) -O2 -S -masm=intel hello.c -o hello.s
	$(CC) -c hello.s -o hello.o && nm hello.o
	objdump -d -r -M intel hello.o
	$(CC) hello.o -o hello && ./hello

phases:
	clang -ccc-print-phases hello.c

temps:
	$(CC) -O2 -save-temps hello.c -o hello && ls -l hello*

sizes:
	$(CC) e01-solution/sizes.c -o sizes && ./sizes

macro:
	$(CC) -E macro.c | tail -5
	$(CC) macro.c -o macro && ./macro

headers:
	$(CC) -H -fsyntax-only hello.c 2>&1 | head -6

builtin:
	$(CC) -O0 -S hello.c -o - | grep call
	$(CC) -O2 -fno-builtin -S hello.c -o - | grep call

static:
	$(CC) -O2 -c hello.c -o hello.o && $(CC) hello.o -o hello
	$(CC) -static hello.o -o hello_static && ls -l hello hello_static
	ldd hello; ldd hello_static || true
	readelf -h hello | grep Entry && nm hello | grep -E ' (_start|main)$$'

clean:
	rm -f hello hello.i hello.s hello.o hello_static macro sizes broken1 broken2 broken3
.PHONY: stages phases temps sizes macro headers builtin static clean
