FLAGS := --pedantic -Wall -Werror

all: bin/ctest

bin/ctest : src/ctest.c | bin
	gcc ${FLAGS} $^ -o $@

bin :
	mkdir $@
