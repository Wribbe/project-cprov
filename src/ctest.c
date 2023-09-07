#include <stdio.h>
#include <time.h>

#define SIZE_TIMESTAMP 30
char TIMESTAMP[SIZE_TIMESTAMP] = {0};
time_t time_raw = {0};
struct tm * time_info = NULL;

char *
timestamp(void)
{
  time_raw = time(NULL);
  time_info = localtime(&time_raw);
  strftime(TIMESTAMP, SIZE_TIMESTAMP, "%Y-%m-%d %H:%M:%S", time_info);
  return TIMESTAMP;
}

#define LOG(LEVEL, fmt, ...)         \
  do {                          \
    if (DEBUG_LEVEL <= LEVEL) { \
      printf("%s - " fmt, timestamp(), __VA_ARGS__);      \
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
  LOG(LOG_DEBUG, "%s\n", "START OF MAIN");
}
