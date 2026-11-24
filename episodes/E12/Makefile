CC = gcc
OBJDUMP = objdump -d -M intel --no-show-raw-insn
PLAIN = -fdiagnostics-plain-output

all: run

# E11 answers: value and type of the six expressions
answers: answers.c
	$(CC) answers.c -o answers && ./answers

# Strict aliasing bug: 0 at -O0, 1 at -O2, 0 with -fno-strict-aliasing
alias: alias.c
	$(CC) -O0 alias.c -o alias && ./alias
	$(CC) -O2 alias.c -o alias && ./alias
	$(CC) -O2 -fno-strict-aliasing alias.c -o alias && ./alias

# The machine code of store() with and without strict aliasing
alias-asm: alias.c
	$(CC) -O2 -c alias.c -o alias.o && $(OBJDUMP) alias.o
	$(CC) -O2 -fno-strict-aliasing -c alias.c -o alias.o && $(OBJDUMP) alias.o

# Type punning: cast (warns, UB), memcpy and union
pun: pun.c
	$(CC) -O2 -Wall $(PLAIN) pun.c -o pun && ./pun

pun-asm: pun.c
	$(CC) -O2 -c pun.c -o pun.o && $(OBJDUMP) pun.o

# restrict: one load fewer
upd-asm: upd.c
	$(CC) -O2 -c upd.c -o upd.o && $(OBJDUMP) upd.o

# restrict speed test at -O2 and -O3
sum: sum.c
	$(CC) -O2 sum.c -o sum && ./sum
	$(CC) -O3 sum.c -o sum && ./sum

run: answers alias pun sum

clean:
	rm -f answers alias alias.o pun pun.o upd.o sum

.PHONY: all run answers alias alias-asm pun pun-asm upd-asm sum clean
