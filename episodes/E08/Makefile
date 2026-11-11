CC ?= gcc
CFLAGS ?=

all: frame_est overflow uaf dfree leak uninit

%: %.c
	$(CC) $(CFLAGS) $< -o $@

run: frame_est
	./frame_est

usage: frame_est.c
	$(CC) -fstack-usage frame_est.c -o frame_est
	cat frame_est.su

# These four crash or abort on purpose when the bug is hit.
overflow: overflow.c
	$(CC) -O0 overflow.c -o overflow

uaf: uaf.c
	$(CC) -O0 -g uaf.c -o uaf

asan-overflow: overflow.c
	$(CC) -g -O0 -fsanitize=address overflow.c -o overflow_asan
	-./overflow_asan

asan-uaf: uaf.c
	$(CC) -g -O0 -fsanitize=address uaf.c -o uaf_asan
	-./uaf_asan

asan-dfree: dfree.c
	$(CC) -g -O0 -fsanitize=address dfree.c -o dfree_asan
	-./dfree_asan

asan-leak: leak.c
	$(CC) -g -O0 -fsanitize=address leak.c -o leak_asan
	-ASAN_OPTIONS=detect_leaks=1 ./leak_asan

vg-leak: leak
	-valgrind --leak-check=full ./leak

vg-uninit: uninit
	-valgrind --track-origins=yes ./uninit

ubsan-uninit: uninit.c
	$(CC) -g -O0 -fsanitize=undefined uninit.c -o uninit_ubsan
	-./uninit_ubsan

exercise: bugs.c
	@echo "Find the three bugs first, then: make asan-bugs and make vg-bugs"

asan-bugs: bugs.c
	$(CC) -g -O0 -fsanitize=address bugs.c -o bugs_asan
	-ASAN_OPTIONS=detect_leaks=1 ./bugs_asan

vg-bugs: bugs.c
	$(CC) -g -O0 bugs.c -o bugs
	-valgrind --track-origins=yes ./bugs

clean:
	rm -f frame_est overflow overflow_asan uaf uaf_asan dfree dfree_asan \
	      leak leak_asan uninit uninit_asan uninit_ubsan bugs bugs_asan *.su

.PHONY: all run usage overflow uaf asan-overflow asan-uaf asan-dfree asan-leak \
        vg-leak vg-uninit ubsan-uninit exercise asan-bugs vg-bugs clean
