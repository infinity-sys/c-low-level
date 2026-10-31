# E01: one function at -O0 and -O2, and a loop with undefined behavior.
CC ?= gcc
dis = objdump -d -M intel --no-show-raw-insn

all: add sum ub asif run addl fix

add:
	$(CC) -O0 -c add.c -o add_O0.o && $(dis) add_O0.o
	$(CC) -O2 -c add.c -o add_O2.o && $(dis) add_O2.o

sum:
	$(CC) -O2 -c sum.c -o sum.o && $(dis) sum.o

ub:
	$(CC) -O0 ub_loop.c -o ub && timeout 3 ./ub; echo "exit $$?"
	$(CC) -O2 ub_loop.c -o ub && timeout 3 ./ub; echo "exit $$?"

arm64:
	clang --target=aarch64-linux-gnu -O2 -c add.c -o add_a64.o
	llvm-objdump -d add_a64.o

asif:
	$(CC) -O2 -c asif.c -o asif.o && $(dis) asif.o

run:
	$(CC) -O0 sum.c sum_main.c -o s && ./s
	$(CC) -O2 sum.c sum_main.c -o s && ./s

addl:
	$(CC) -O2 -c addl.c -o addl.o && $(dis) addl.o

fix:
	$(CC) -O0 -fsanitize=undefined ub_loop.c -o ub && ./ub
	$(CC) -O2 -fwrapv ub_loop.c -o ub && timeout 3 ./ub; echo "exit $$?"

clean:
	rm -f *.o ub s
.PHONY: all add sum ub arm64 asif run addl fix clean
