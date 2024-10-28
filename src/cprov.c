#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define ASSERT(b, msg, ...) \
  if (!b) { \
    printf("[FAILED]: "msg, __VA_ARGS__); \
    return false; \
  } \
  printf("%s\n", "[PASSED]"); \

#define MSG(fmt, ...)


bool
match(const char * string, const char * match)
{
  return strcmp(string, match) == 0;
}


const char *
filename(const char * string)
{
  const char * match = string;
  while (*string != '\0') {
    if (*string == '/') {
      match = string+1;
    }
    string++;
  }
  return match;
}


bool
test_match(void)
{
  const char * foo = "foo";
  const char * bar = "bar";
  const char * foobar = "foobar";

  ASSERT(!match(foo, bar), "%s should not match %s.\n", foo, bar);
  ASSERT(match(bar, bar), "%s should match %s.\n", bar, bar);
  ASSERT(!match(foobar, bar), "%s should not match %s.\n", foobar, bar);

  return true;
}


bool
test_filename(void)
{
  const char * path = "/a/b/c";
  const char * name = "c";
  ASSERT(match(filename(path), name), "Filename of %s should be %s.\n", path, name);

  return true;
}

bool
strp_match(const char * a, const char * b)
{
  return *a == *b;
}

bool
strp_null(const char * str)
{
  return *str == '\0';
}


bool
has_prefix(const char * prefix, const char * string)
{
  while(!strp_null(prefix) && !strp_null(string)) {
    if (!strp_match(prefix, string)) {
      return false;
    }
    if (strp_null(prefix) || strp_null(string)) {
      return false;
    }
    prefix++;
    string++;
  }
  return true;
}


bool
test_has_prefix(void)
{
  const char * prefix = "prefix_";
  const char * full = "prefix_rest";
  const char * wrong_prefix = "prefik_rest";
  ASSERT(!has_prefix(prefix, wrong_prefix),
    "%s does not start with %s\n", wrong_prefix, full
  );
  ASSERT(has_prefix(prefix, full),
    "%s does start with %s\n", prefix, full
  );
  return true;
}


int
main(void)
{
  test_match();
  test_filename();
  test_has_prefix();
}
