#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"
#include "ctest.h"
int main(int argc, char* argv[]) {
  CTEST_BEGIN();

  cstring s = cstring_newlen("abc", 3);
  CTEST_COND("cstring_newlen", !memcmp(s, "abc", 4));
  cstring_clear(s);

  s = cstring_newstr("hello");
  CTEST_COND("cstring_newstr", !memcmp(s, "hello", 6));
  cstring_clear(s);

  s = cstring_newstr("world");
  CTEST_COND("cstring_len", cstring_len(s) == 5);
  cstring_clear(s);

  CTEST_END();

  exit(EXIT_SUCCESS);
}