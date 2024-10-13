#include <stdio.h>
#include <stdint.h>

#define TEST_FAILURE 0
#define TEST_SUCCESS 1
#define TEST_RETURN uint8_t

struct ctest_result {
  size_t total;
  size_t passed;
  size_t failed;
};
