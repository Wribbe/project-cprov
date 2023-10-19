FLAGS := --pedantic -Wall -Werror -Ilib
BIN := $(patsubst src/%.c,bin/%,$(wildcard src/*.c))
TEST := $(patsubst src/test/%.c,bin/.test/%,$(wildcard src/test/*.c))
TEMPS := $(patsubst src/test/%,.tmp/%,$(wildcard src/test/*.c))

all: ${BIN} ${TEMPS} ${TEST}

BUILD = gcc ${FLAGS} $^ -o $@

.tmp/% : src/test/% bin/ctest_gen | .tmp
	bin/ctest_gen $^ > $@

bin/.test/% : lib/ctest.h .tmp/%.c | bin/.test
	${BUILD}

bin/% : src/%.c | bin
	${BUILD}

bin bin/.test .tmp:
	mkdir -p $@

.SUFFIXES:
