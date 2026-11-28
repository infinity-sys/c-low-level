CC = gcc
OBJDUMP = objdump -d -M intel --no-show-raw-insn
PLAIN = -fdiagnostics-plain-output

all: run

# E12 answers: cast vs memcpy (one -Wstrict-aliasing warning, same values)
answers: answers.c
	$(CC) -O2 -Wall $(PLAIN) answers.c -o answers && ./answers

answers-asm: answers.c
	$(CC) -O2 -c answers.c -o answers.o && $(OBJDUMP) answers.o

# The bonus: misaligned uint16_t load (needs clang)
answers-ubsan: answers.c
	clang -fsanitize=alignment answers.c -o answers && ./answers

# The as-if rule: an empty loop vanishes at -O2, a volatile one stays
spin: spin.c
	$(CC) -O0 spin.c -o spin && ./spin
	$(CC) -O2 spin.c -o spin && ./spin

spin-asm: spin.c
	$(CC) -O2 -c spin.c -o spin.o && $(OBJDUMP) spin.o

# A signal flag: plain int hangs at -O2 (timeout exit 124), volatile sig_atomic_t works
flag: flag.c
	-$(CC) -O0 flag.c -o flag && timeout 3 ./flag; echo exit $$?
	-$(CC) -O2 flag.c -o flag && timeout 3 ./flag; echo exit $$?
	-$(CC) -O2 -DFIXED flag.c -o flag && timeout 3 ./flag; echo exit $$?

flag-asm: flag.c
	$(CC) -O2 -c flag.c -o flag.o && objdump -dr -M intel --no-show-raw-insn flag.o
	$(CC) -O2 -DFIXED -c flag.c -o flag.o && objdump -dr -M intel --no-show-raw-insn flag.o

# volatile is not for threads: the volatile count loses updates, _Atomic does not
race: race.c
	$(CC) -O2 race.c -o race && ./race

race-asm: race.c
	$(CC) -O2 -c race.c -o race.o && objdump -dr -M intel --no-show-raw-insn race.o

# const: a pointer to const vs a const object; BAD shows the compile error
const: const.c
	$(CC) -O2 -Wall const.c -o const && ./const
	-$(CC) -O2 -DBAD $(PLAIN) -c const.c -o const.o

const-asm: const.c
	$(CC) -O2 -c const.c -o const.o && $(OBJDUMP) const.o

run: answers spin flag race const

clean:
	rm -f answers answers.o spin spin.o flag flag.o race race.o const const.o

.PHONY: all run answers answers-asm answers-ubsan spin spin-asm flag flag-asm race race-asm const const-asm clean
