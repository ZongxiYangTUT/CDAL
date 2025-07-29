#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
void ctest_begin(void);
void ctest_end(void);
void ctest_cond(const char* desc, bool expr);

#define CTEST_BEGIN() ctest_begin()
#define CTEST_END() ctest_end()
#define CTEST_COND(desc, expr) ctest_cond(desc, expr)

#endif