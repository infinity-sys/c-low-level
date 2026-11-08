CC ?= gcc
CFLAGS ?=

all: pow2_sol frames depth vla

%: %.c
	$(CC) $(CFLAGS) $< -o $@

run: all
	./pow2_sol; setarch -R ./frames || ./frames
	./vla 1000

gdb: frames.c      # bt and the frames of main, b and c
	$(CC) -g frames.c -o framesg
	gdb -q -batch -ex "break 6" -ex run -ex bt -ex "p &z" -ex "frame 1" -ex "p &y" ./framesg

usage: depth.c     # frame size of dive(): depth.su
	$(CC) -fstack-usage depth.c -o depth
	cat depth.su

depth: depth       # crashes on purpose (stack overflow)
	-./depth 2> log; head -2 log; tail -1 log

crash: vla         # a 100,000,000-byte VLA: crashes on purpose
	-./vla 100000000

exercise: frame_est.c
	@echo "Estimate the frame of work() first, then: make check-exercise"

check-exercise: frame_est.c
	$(CC) -fstack-usage frame_est.c -o frame_est
	cat frame_est.su

clean:
	rm -f pow2_sol frames framesg depth vla frame_est *.su log

.PHONY: all run gdb usage depth crash exercise check-exercise clean
