#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"
#include "ctest.h"
int main(int argc, char* argv[]) {
  CTEST_BEGIN();

  cstring s = cstring_newlen("abc", 3);
  CTEST_COND("cstring_newlen", !memcmp(s, "abc", 4));
  cstring_free(s);

  s = cstring_newstr("hello");
  CTEST_COND("cstring_newstr", !memcmp(s, "hello", 6));
  cstring_free(s);

  s = cstring_newstr("world");
  CTEST_COND("cstring_len", cstring_len(s) == 5);
  cstring_free(s);

  s = cstring_empty();
  CTEST_COND("cstring_empty", cstring_len(s) == 0);

  cstring s1 = cstring_newstr("test cstring");
  cstring s2 = cstring_copy(s1);
  CTEST_COND("cstring_copy", cstring_equal(s1, s2));
  cstring_free(s1);
  cstring_free(s2);

  CTEST_END();

  exit(EXIT_SUCCESS);
}