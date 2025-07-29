#include <stdlib.h>

#include "CString.h"
#include "CTest.h"
int main(int argc, char* argv[]) {
  CTEST_BEGIN();
  CTEST_COND("abc", 1 == 2);
  CTEST_COND("abc", 1 == 1);

  CTEST_END();

  exit(EXIT_SUCCESS);
}