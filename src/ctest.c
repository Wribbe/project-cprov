#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define LEN(array) (sizeof(array) / sizeof(array[0]))

#define CTEST_ASSERT(res, fmt_msg, ...)               \
  do {                                                \
    if (!(res)) {                                     \
      fprintf(stderr, "Error: "fmt_msg, __VA_ARGS__); \
      return EXIT_FAILURE;                            \
    }                                                 \
  } while (0)


struct ctest_state {
  uint64_t num_tests;
};


void
ctest_run(struct ctest_state * state, const char * test_list[])
{
}


int
main(int argc, const char ** argv)
{

  const char * test_list[] = {
    "fake/test_file.c",
    "test_method_1",
    "test_method_2",
    "test_method_3",
    NULL
  };

  struct ctest_state state = {0};
  ctest_run(&state, test_list);
  CTEST_ASSERT_EQ(
    state.num_tests == LEN(test_list)-1,
    "%zu tests were run instead of %zu\n",
    state.num_tests,
    LEN(test_list)-1
  );
}
