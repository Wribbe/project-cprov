FLAGS := --pedantic -Wall -Werror -Ilib
BIN := $(patsubst src/%.c,bin/%,$(wildcard src/*.c))
TEST := $(patsubst src/test/%.c,bin/test/%,$(wildcard src/test/*.c))

all: ${BIN} ${TEST}
	echo ${BIN}
	echo ${TEST}

BUILD = gcc ${FLAGS} $^ -o $@

bin/test/% : tmp/%.c lib/ctest.h | bin/test
	${BUILD}

bin/% : src/%.c | bin
	${BUILD}

tmp/%.c : src/test/%.c bin/ctest_gen | tmp
	bin/ctest_gen $^ > $@

bin bin/test tmp:
	mkdir -p $@
