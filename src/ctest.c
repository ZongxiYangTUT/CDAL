#include "ctest.h"

#include <stdio.h>
static int total, passed;

void ctest_begin(void) { total = passed = 0; }

void ctest_end(void) {
  printf("total = %d, passed = %d, pass rate = %.2f%%\n", total, passed,
         (double)passed / total * 100.0);
}

void ctest_cond(const char* desc, bool expr) {
  total++;
  if (expr) {
    passed++;
    printf("[\033[32mPassed\033[0m] %s\n", desc);  // green
  } else {
    printf("[\033[31m Error\033[0m] %s\n", desc);  // red
  }
}