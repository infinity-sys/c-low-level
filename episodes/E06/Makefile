CC ?= gcc
CFLAGS ?=

all: six_sol bytes detect swap file bits popcount bitfield check

%: %.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	./six_sol; setarch -R ./bytes || ./bytes; ./detect; ./swap
	./file; xxd raw.bin; ./bits; ./popcount; ./bitfield; ./check

gdb: bytes.c      # the same 4 bytes, as bytes and as a word
	$(CC) -g bytes.c -o bytes
	gdb -q -batch -ex "break 9" -ex run -ex "x/4xb &x" -ex "x/1xw &x" ./bytes

asm: swap.c popcount.c   # swap32 -> bswap, popcount -> popcnt
	$(CC) -O2 -S -masm=intel swap.c -o swap.s
	$(CC) -O2 -mpopcnt -S -masm=intel popcount.c -o pop.s

exercise: pow2
	./pow2

clean:
	rm -f six_sol bytes detect swap file bits popcount bitfield check pow2 raw.bin swap.s pop.s

.PHONY: all run gdb asm exercise clean
