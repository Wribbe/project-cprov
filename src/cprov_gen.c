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

int
main(int argc, const char ** argv)
{
  for (int ii=0; ii<argc; ii++) {
    fprintf(stderr, "Arg[%d]: %s\n", ii, argv[ii]);
  }
  printf("%s\n", includes);
  printf("%s", head);
  printf("%s\n", "  printf(\"%s\\n\", \"HELLO WORLD\");");
  printf("%s", tail);
}