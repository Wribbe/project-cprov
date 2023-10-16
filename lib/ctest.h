#include <stdbool.h>

#define CTEST bool
#define CTEST_ASSERT(eq, fmt, ...) do {\
    if (!(eq)) {        \
      return false;     \
    };                  \
    return true;        \
  } while(0);

struct ctest {
  void * hello;
};
