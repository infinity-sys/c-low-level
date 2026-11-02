CC ?= gcc
CFLAGS ?=

all: layout maps grow bss_big data_big

layout: layout.c
	$(CC) -g $(CFLAGS) $< -o $@

maps grow bss_big data_big bss_2m: %: %.c
	$(CC) $(CFLAGS) $< -o $@

run: layout          # ASLR off for one run, so addresses match the video
	setarch -R ./layout

sections: layout     # which section each name is in
	size layout
	nm -n layout | grep -wf syms

map: maps
	setarch -R ./maps

grow-run: grow
	setarch -R ./grow

bss: bss_big data_big   # 4 MB of zeros cost nothing on disk
	stat -c '%8s  %n' bss_big data_big
	size bss_big data_big

aslr: layout         # run twice: only the base moves
	./layout | head -3
	./layout | head -3

clean:
	rm -f layout maps grow bss_big data_big bss_2m *.o

.PHONY: all run map sections grow-run bss aslr clean
