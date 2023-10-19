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
  printf("%s\n", includes);
  printf("%s", head);
  printf("%s\n", "  printf(\"%s\\n\", \"HELLO WORLD\");");
  printf("%s", tail);
}
