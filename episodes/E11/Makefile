CC = gcc
OBJDUMP = objdump -d -M intel --no-show-raw-insn
PLAIN = -fdiagnostics-plain-output

all: run

# E10 answers: the six snippets, with two UBSan checks
snippets: snippets.c
	$(CC) -fsanitize=bounds,signed-integer-overflow snippets.c -o snippets
	./snippets

# Integer promotion: 200 + 100 is 300, not 44
promo: promo.c
	$(CC) promo.c -o promo && ./promo

# The trap: -1 < 1u is false
cmp: cmp.c
	$(CC) cmp.c -o cmp && ./cmp

# Same cmp, setl (signed) vs setb (unsigned)
lt-asm: lt.c
	$(CC) -O2 -c lt.c -o lt.o && $(OBJDUMP) lt.o

# uint16_t * uint16_t overflows int (UBSan reports it)
mul: mul.c
	$(CC) mul.c -o mul && ./mul
	$(CC) -fsanitize=undefined mul.c -o mul_ub && ./mul_ub

# Warnings: -Wsign-compare (in -Wextra) and -Wconversion
warn: cmp.c conv.c
	-$(CC) -Wall -Wextra $(PLAIN) -c cmp.c -o /dev/null
	$(CC) conv.c -o conv && ./conv
	$(CC) -Wall -Wextra -c conv.c -o /dev/null && echo no warnings
	-$(CC) -Wall -Wextra -Wconversion $(PLAIN) -c conv.c -o /dev/null

# The fix: sign check first, C23 ckd_add / ckd_mul (GCC 14+, Clang 18+)
safe: safe.c
	$(CC) -std=c23 -Wall -Wextra safe.c -o safe && ./safe

run: snippets promo cmp mul safe

clean:
	rm -f snippets promo cmp lt.o mul mul_ub conv safe

.PHONY: all run snippets promo cmp lt-asm mul warn safe clean
