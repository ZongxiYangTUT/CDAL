#include <string>

#include "cstring.h"
#include "ctest.h"

#define MAX_COUNT 1000000000

void benchmark_cstring_push_back() {
  cstring s = cstring_empty();
  for (size_t i = 0; i < MAX_COUNT; i++) {
    s = cstring_push_back(s, rand() % 128);
  }
  cstring_free(s);
}

void benchmark_string_push_back() {
  std::string str;
  for (size_t i = 0; i < MAX_COUNT; i++) {
    str.push_back(rand() % 128);
  }
}

void benchmark_cstring_resize() {
  cstring s = cstring_empty();
  for (size_t i = 0; i < MAX_COUNT; i++) {
    s = cstring_resize(s, rand() % MAX_COUNT);
  }
  cstring_free(s);
}

void benchmark_string_resize() {
  std::string str;
  for (size_t i = 0; i < MAX_COUNT; i++) {
    str.resize(rand() % MAX_COUNT);
  }
}

void benchmark_cstring() {
  CTEST_ELAPSED_BEGIN(cstring_push_back);
  benchmark_cstring_push_back();
  CTEST_ELAPSED_END(cstring_push_back);

  CTEST_ELAPSED_BEGIN(string_push_back);
  benchmark_string_push_back();
  CTEST_ELAPSED_END(string_push_back);

  CTEST_ELAPSED_BEGIN(cstring_resize);
  benchmark_cstring_resize();
  CTEST_ELAPSED_END(cstring_resize);

  CTEST_ELAPSED_BEGIN(string_resize);
  benchmark_string_resize();
  CTEST_ELAPSED_END(string_resize);
}

int main(int argc, char* argv[]) {
  benchmark_cstring();
  return 0;
}