CC ?= gcc
OBJDUMP = objdump -d -M intel --no-show-raw-insn

all: run

# E09 quiz solutions
quiz: quiz.c
	$(CC) -O0 quiz.c -o quiz

# Demo 1: the same overflow check, three builds (clang 1 / 0, gcc 0)
ovf-run: ovf.c
	-clang -O0 ovf.c -o ovf && ./ovf
	-clang -O2 ovf.c -o ovf && ./ovf
	$(CC) -O0 ovf.c -o ovf && ./ovf

ovf-asm: ovf.c
	-clang -O0 -c ovf.c -o ovf_c0.o && $(OBJDUMP) --disassemble=will_overflow ovf_c0.o
	-clang -O2 -c ovf.c -o ovf_c2.o && $(OBJDUMP) --disassemble=will_overflow ovf_c2.o
	$(CC) -O0 -c ovf.c -o ovf_g0.o && $(OBJDUMP) --disassemble=will_overflow ovf_g0.o

# The fix, -fwrapv, and UBSan
fix: ovf_fix.c ovf.c
	$(CC) -O2 -Wall ovf_fix.c -o ovf_fix && ./ovf_fix
	$(CC) -O2 -fwrapv ovf.c -o ovf_wrapv && ./ovf_wrapv
	$(CC) -fsanitize=undefined ovf.c -o ovf_ub && ./ovf_ub

# Demo 2: the null check after the read
null-asm: null.c
	$(CC) -O0 -c null.c -o null_O0.o && $(OBJDUMP) --disassemble=first null_O0.o
	$(CC) -O2 -c null.c -o null_O2.o && $(OBJDUMP) --disassemble=first null_O2.o
	$(CC) -O2 -fno-delete-null-pointer-checks -c null.c -o null_keep.o && $(OBJDUMP) --disassemble=first null_keep.o

# Unspecified and implementation-defined
kinds: kinds.c
	$(CC) -Wall -Wextra kinds.c -o kinds && ./kinds

run: quiz
	./quiz
	$(MAKE) ovf-run fix kinds

clean:
	rm -f quiz ovf ovf_fix ovf_wrapv ovf_ub kinds *.o

.PHONY: all run ovf-run ovf-asm fix null-asm kinds clean
