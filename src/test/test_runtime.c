#include "cprov.h"

CTEST
test_return_value(struct cprov * runtime)
{
  CTEST_ASSERT(1 == 1, "%s\n", "One does not equal one");
}
