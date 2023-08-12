FLAGS := --pedantic -Wall


all: bin/ctest

bin/ctest : src/ctest.c | bin
	gcc $^ -o $@ ${FLAGS}

bin :
	mkdir $@
