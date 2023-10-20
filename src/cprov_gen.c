#include <stdlib.h>
#include <stdio.h>

const char * includes = \
 "#include <stdlib.h>\n"
 "#include <stdio.h>\n";

const char * head = \
  "int\n"
  "main (void)\n"
  "{\n";

const char * tail = \
  "}\n";


#define FATAL(fmt, ...) fprintf(stderr, "FATAL: "fmt, __VA_ARGS__); exit(EXIT_FAILURE);
#define ERROR(fmt, ...) fprintf(stderr, "ERROR: "fmt, __VA_ARGS__);


char *
read_source(const char * filename)
{
  FILE * fh = fopen(filename, "r");
  if (fh == NULL) {
    FATAL("Could not read source, no such file: %s\n", filename);
  }

  fseek(fh, 0L, SEEK_END);
  size_t size_source = ftell(fh);
  rewind(fh);

  char * source = malloc(size_source+1);
  if (source == NULL) {
    ERROR("Could not allocate memory for reading %s\n", filename);
    goto cleanup;
  }

  size_t size_read = 0;
  while(size_read < size_source) {
    size_read += fread(source+size_read, 1, size_source, fh);
  }

cleanup:

  if (fh != NULL) {
    fclose(fh);
  }

  return source;

}


char *
test_calls(const char * source, size_t * num_found)
{
  size_t max_calls = 512;
}


int
main(int argc, const char ** argv)
{

  if (argc < 2) {
    fprintf(stderr, "Usage: %s PATH_SOURCE_FILE\n", argv[0]);
    return EXIT_FAILURE;
  }

  for (int ii=0; ii<argc; ii++) {
    fprintf(stderr, "Arg[%d]: %s\n", ii, argv[ii]);
  }

  char * source = read_source(argv[1]);
  fprintf(stderr, "source: %s\n", source);

  printf("%s\n", includes);
  printf("%s", head);
  printf("%s\n", "  printf(\"%s\\n\", \"HELLO WORLD\");");
  printf("%s", tail);

  free(source);
}
