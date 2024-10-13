FLAGS := -g

all: bin/ctest

bin/% : src/%.c | bin
	gcc $^ ${FLAGS} -o $@

bin:
	mkdir $@
