CC ?= gcc
CFLAGS ?=

all: p3_sol align pad packed tail six check

%: %.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	./p3_sol; ./align; ./pad; ./packed; setarch -R ./tail; ./check

ptype: pad.c      # holes and padding, shown by GDB
	$(CC) -g pad.c -o pad
	gdb -q -batch -ex "ptype /o struct bad" -ex "ptype /o struct good" ./pad

asm: packed.c     # the misaligned load
	$(CC) -O2 -S -masm=intel packed.c -o packed.s

exercise: six
	./six

clean:
	rm -f p3_sol align pad packed tail six check packed.s

.PHONY: all run ptype asm exercise clean
