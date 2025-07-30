#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

void ctest_begin(void);
void ctest_end(void);
void ctest_cond(const char* desc, bool expr);

#define CTEST_BEGIN() ctest_begin()
#define CTEST_END() ctest_end()
#define CTEST_COND(desc, expr) ctest_cond(desc, expr)

#define CTEST_ELAPSED_BEGIN(group) time_t group##begin = time(NULL)

#define CTEST_ELAPSED_END(group)  \
  time_t group##end = time(NULL); \
  printf("%10s: %.3f s\n", #group, difftime(group##end, group##begin))

#ifdef __cplusplus
}
#endif

#endif