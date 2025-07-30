#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"
#include "ctest.h"

void test_cstring() {
  CTEST_BEGIN();

  cstring s = cstring_newlen("abc", 3);
  CTEST_COND("cstring_newlen", memcmp(s, "abc", 4) == 0);
  cstring_free(s);

  s = cstring_newstr("hello");
  CTEST_COND("cstring_newstr", memcmp(s, "hello", 6) == 0);
  cstring_free(s);

  s = cstring_newstr("world");
  CTEST_COND("cstring_size", cstring_size(s) == 5);
  cstring_free(s);

  s = cstring_empty();
  CTEST_COND("cstring_empty", cstring_size(s) == 0);

  cstring s1 = cstring_newstr("test cstring");
  cstring s2 = cstring_copy(s1);
  CTEST_COND("cstring_copy", cstring_equal(s1, s2));
  cstring_free(s1);
  cstring_free(s2);

  s = cstring_newstr("test pop");
  CTEST_COND("cstring_front", cstring_front(s) == 't');
  cstring_pop_back(s);
  CTEST_COND("cstring_back", cstring_back(s) == 'o');
  cstring_free(s);

  s = cstring_newstr("hello");
  s = cstring_cat(s, "world");
  CTEST_COND("cstring_cat", strcmp(s, "helloworld") == 0);

  s = cstring_catlen(s, "1234\0ab", 7);
  CTEST_COND("cstring_catlen", strcmp(s, "helloworld1234\0ab") == 0);

  cstring_clear(s);
  s = cstring_catcstring(s, s);
  CTEST_COND("cstring_catcstring", strcmp(s, "") == 0);

  s = cstring_push_back(s, 'a');
  CTEST_COND("cstring_push_back", strcmp(s, "a") == 0);
  cstring_free(s);

  s = cstring_empty();
  cstring_cpy(s, "test cpy");
  CTEST_COND("cstring_cpy", strcmp(s, "test cpy") == 0);

  cstring_cpylen(s, "\0\0\n", 3);
  CTEST_COND("cstring_cpylen", memcmp(s, "\0\0\n", 3) == 0);

  s = cstring_resize(s, 2);
  CTEST_COND("cstring_resize", memcmp(s, "\0\0", 2) == 0);

  s = cstring_reserve(s, 10);
  CTEST_COND("cstring_capacity", cstring_capacity(s) >= 10);
  cstring_free(s);

  s = cstring_newstr("abCD");
  cstring_toupper(s);
  CTEST_COND("cstring_toupper", strcmp(s, "ABCD") == 0);

  cstring_tolower(s);
  CTEST_COND("cstring_tolower", strcmp(s, "abcd") == 0);
  cstring_free(s);

  s = cstring_newstr("  \n \r \t \v \f abcd: ~-+ \r");
  s = cstring_trim(s, " \r\n\t\v\f");
  CTEST_COND("cstring_trim", strcmp(s, "abcd: ~-+") == 0);
  cstring_clear(s);

  cstring_cat(s, " \n");
  s = cstring_trim(s, " \n");
  CTEST_COND("cstring_trim", strcmp(s, "") == 0);

  cstring_free(s);

  s = cstring_newstr("hello world");
  CTEST_COND("cstring_find", cstring_find(s, NULL) == false);
  CTEST_COND("cstring_start_with",
             cstring_start_with(s, "hedasdddddddddsadas") == false);
  CTEST_COND("cstring_end_with",
             cstring_end_with(s, "ldsssssssssssssd") == false);

  cstring_free(s);
  CTEST_END();
}

int main(int argc, char* argv[]) {
  test_cstring();
  exit(EXIT_SUCCESS);
}