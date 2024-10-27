FLAGS := -g

all: bin/cprov

bin/%: src/%.c | bin
	gcc $^ -o $@ ${FLAGS}

bin:
	mkdir -p $@
