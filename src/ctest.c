#include "ctest.h"


struct ctest_result
run(void)
{
  struct ctest_result result = {0};
  return result;
}


int
main(void)
{
  struct ctest_result result = run();
  printf("Ran %zu tests where %zu passed and %zu failed.\n",
      result.total,
      result.passed,
      result.failed
  );
}
