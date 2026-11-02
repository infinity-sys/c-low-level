CC ?= gcc
CFLAGS ?=

all: arith decay alias_run mem check p3

arith decay check p3: %: %.c
	$(CC) $(CFLAGS) $< -o $@

mem: mem.c
	$(CC) -g -O0 $(CFLAGS) $< -o $@

alias_run: alias.c alias_run.c
	$(CC) -O2 $(CFLAGS) $^ -o $@

run: arith decay   # ASLR off, so addresses match the video
	setarch -R ./arith
	setarch -R ./decay

asm: alias.c       # same reloads *a, other and noalias return 1
	$(CC) -O2 -S -masm=intel alias.c -o alias.s

gdb: mem
	setarch -R gdb -q ./mem

solution: place.c  # the E03 exercise
	$(CC) -c place.c && nm place.o

clean:
	rm -f arith decay alias_run mem check p3 place.o alias.s

.PHONY: all run asm gdb solution clean
