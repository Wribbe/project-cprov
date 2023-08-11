#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


#define CTEST_MAIN_RUNNER                 \
  "int\n"                                 \
  "main(int argc, const char ** argv)\n"  \
  "{\n"                                   \


#define PATH_DEST_BIN "bin/"
#define PATH_DEST_SRC_TEST "src/test"
#define PATH_DEST_PREFIX "_test_"


struct ctest_state {
  uint64_t num_tests;
};


int
ctest_compile(struct ctest_state * state, const char * tests[], uint64_t num_tests)
{


  const char * path_test = tests[0];
  LOG(LOG_DEBUG, "Reading test-source from %s\n", path_test);

  FILE * handle_src = fopen(path_test, "r");
  if (handle_src == NULL) {
    printf("No such file %s\n", path_test);
    return EXIT_FAILURE;
  }

  fseek(handle_src, 0, SEEK_END);
  size_t size_file = ftell(handle_src);
  rewind(handle_src);

  char buffer_src[size_file+1];
  size_t size_read = 0;
  while (size_read < size_file) {
    size_read += fread(buffer_src, 1, size_file, handle_src);
  }

  fclose(handle_src);

  printf("src: >>>\n%s\n%s<<<\n", buffer_src, CTEST_MAIN_RUNNER);

  size_t size_path_dest =
    sizeof(path_test)+\
    sizeof(PATH_DEST_BIN)+\
    sizeof(PATH_DEST_PREFIX)+\
    sizeof(PATH_DEST_SRC_TEST);

  char buffer_path_dest[size_path_dest];

  LOG(LOG_DEBUG, "THE MODIFIED SOURCE WILL BE WRITTEN TO %s\n", "NULL");

  strcpy(buffer_path_dest, PATH_DEST_BIN);
//  strcat(buffer_path_dest,

  return EXIT_SUCCESS;
}


void
ctest_run_test(struct ctest_state * state, const char * path, const char * method)
{
  state->num_tests++;
}


void
ctest_run(struct ctest_state * state, const char * tests[], uint64_t num_tests)
{
  const char * path = tests[0];
  ctest_compile(state, tests, num_tests);
  for (uint64_t ii=1; ii<=num_tests; ii++) {
    ctest_run_test(state, path, tests[ii]);
  }
}


int
main(int argc, const char ** argv)
{

  const char * tests[] = {
    "test/test.c",
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
