all: bin/ctest


bin/ctest : src/ctest.c | bin
	gcc $^ -o $@


bin:
	mkdir -p $@
