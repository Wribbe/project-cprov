#include <stdio.h>

#define LOG(LEVEL, ...)         \
  do {                          \
    if (DEBUG_LEVEL <= LEVEL) { \
      printf(__VA_ARGS__);      \
    }                           \
  } while(0)


enum LOG_LEVEL {
  LOG_FATAL
  ,LOG_ERROR
  ,LOG_WARNING
  ,LOG_INFO
  ,LOG_DEBUG
};


#define DEBUG_LEVEL LOG_DEBUG


int
main(int argc, char ** argv)
{
  LOG(LOG_DEBUG, "START OF MAIN\n");
}
