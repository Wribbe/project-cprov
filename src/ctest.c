#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define LEN(array) (sizeof(array) / sizeof(array[0]))
#define NUM_TESTS(tests) LEN(tests)-1


enum LOG_LEVEL {
  LOG_FATAL,
  LOG_ERROR,
  LOG_WARNING,
  LOG_INFO,
  LOG_DEBUG
};


#define debug_level LOG_DEBUG


#define LOG(level, ...)         \
  do {                          \
    if (level <= debug_level) { \
      printf(__VA_ARGS__);      \
    }                           \
  } while (0)


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
ctest_run_test(struct ctest_state * state, const char * path, const char * method)
{
  state->num_tests++;
}


void
ctest_run(struct ctest_state * state, const char * tests[], uint64_t num_tests)
{
  const char * path = tests[0];
  for (uint64_t ii=1; ii<=num_tests; ii++) {
    ctest_run_test(state, path, tests[ii]);
  }
}


int
main(int argc, const char ** argv)
{

  const char * tests[] = {
    "fake/test_file.c",
    "test_method_1",
    "test_method_2",
    "test_method_3"
  };

  struct ctest_state state = {0};
  ctest_run(&state, tests, NUM_TESTS(tests));

  CTEST_ASSERT(
    state.num_tests == NUM_TESTS(tests),
    "%zu tests were run instead of %zu\n",
    state.num_tests,
    NUM_TESTS(tests)
  );
}
