#include "ctest.h"

CTEST
test_return_value(struct ctest * runtime)
{
  CTEST_ASSERT(1 == 1, "%s\n", "One does not equal one");
}
