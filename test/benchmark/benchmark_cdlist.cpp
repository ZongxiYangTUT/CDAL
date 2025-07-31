#include <list>

#include "cdlist.h"
#include "ctest.h"
#define MAX_COUNT 100000000
void benchmark_cdlist_push_pop_back() {
  cdlist* l = cdlist_create();
  for (size_t i = 0; i < MAX_COUNT; i++) {
    l = cdlist_push_back(l, NULL);
  }

  for (size_t i = 0; i < MAX_COUNT; i++) {
    cdlist_pop_back(l);
  }

  cdlist_free(l);
}

void benchmark_list_push_pop_back() {
  std::list<void*> l;
  for (size_t i = 0; i < MAX_COUNT; i++) {
    l.push_back(nullptr);
  }

  for (size_t i = 0; i < MAX_COUNT; i++) {
    l.pop_back();
  }
}

void benchmark_cdlist_push_pop_front() {
  cdlist* l = cdlist_create();
  for (size_t i = 0; i < MAX_COUNT; i++) {
    l = cdlist_push_front(l, NULL);
  }

  for (size_t i = 0; i < MAX_COUNT; i++) {
    cdlist_pop_front(l);
  }

  cdlist_free(l);
}

void benchmark_list_push_pop_front() {
  std::list<void*> l;
  for (size_t i = 0; i < MAX_COUNT; i++) {
    l.push_front(nullptr);
  }

  for (size_t i = 0; i < MAX_COUNT; i++) {
    l.pop_front();
  }
}

void benchmark_cdlist() {
  CTEST_ELAPSED_BEGIN(cdlist_push_back);
  benchmark_cdlist_push_pop_back();
  CTEST_ELAPSED_END(cdlist_push_back);

  CTEST_ELAPSED_BEGIN(list_push_back);
  benchmark_list_push_pop_back();
  CTEST_ELAPSED_END(list_push_back);

  CTEST_ELAPSED_BEGIN(cdlist_push_front);
  benchmark_cdlist_push_pop_front();
  CTEST_ELAPSED_END(cdlist_push_front);

  CTEST_ELAPSED_BEGIN(list_push_front);
  benchmark_list_push_pop_front();
  CTEST_ELAPSED_END(list_push_front);
}

int main(int argc, char* argv[]) {
  benchmark_cdlist();

  return 0;
}