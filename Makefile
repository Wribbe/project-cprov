FLAGS := -Wall --pedantic

all: bin/ctest


bin/ctest : src/ctest.c Makefile | bin
	gcc $(filter %.c,$^) -o $@ ${FLAGS}


bin:
	mkdir -p $@
