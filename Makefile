FLAGS := --pedantic -Wall -Werror -Ilib
BIN := $(patsubst src/%.c,bin/%,$(wildcard src/*.c))
TEST := $(patsubst src/test/%.c,bin/.test/%,$(wildcard src/test/*.c))
TEMPS := $(patsubst src/test/%,.tmp/%,$(wildcard src/test/*.c))

all: ${BIN} ${TEMPS} ${TEST}

BUILD = gcc ${FLAGS} $^ -o $@

.tmp/% : src/test/% bin/cprov_gen | .tmp
	bin/cprov_gen $(filter %.c,$^) > $@

bin/.test/% : lib/cprov.h .tmp/%.c | bin/.test
	${BUILD}

bin/% : src/%.c | bin
	${BUILD}

bin bin/.test .tmp:
	mkdir -p $@

.SUFFIXES:
