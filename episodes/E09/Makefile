CC ?= gcc
CFLAGS ?= -O0 -g -Wall

Q = q1_sizeof q2_arith q3_pad q4_str q5_endian q6_index q7_incr q8_local

all: $(Q)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

# The eight questions. q4_str and q8_local crash on purpose (status 139).
run: $(Q)
	@for q in $(Q); do echo "== $$q"; ./$$q; echo "status $$?"; done

# E08 answers
answer-warn: bugs.c
	-$(CC) -g -O0 -Wall bugs.c -o bugs

answer-asan: bugs.c
	$(CC) -g -O0 -fsanitize=address bugs.c -o bugs_asan
	-ASAN_OPTIONS=detect_leaks=1 ./bugs_asan

answer-vg: bugs_fix1.c
	$(CC) -g -O0 bugs_fix1.c -o bugs_fix1
	-valgrind --track-origins=yes ./bugs_fix1

clean:
	rm -f $(Q) bugs bugs_asan bugs_fix1

.PHONY: all run answer-warn answer-asan answer-vg clean
