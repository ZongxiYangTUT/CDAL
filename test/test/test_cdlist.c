#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdlist.h"
#include "ctest.h"

void test_cdlist() {
  CTEST_BEGIN();
  cdlist* l = cdlist_create();
  int arr[] = {1, 2, 3};
  l = cdlist_push_back(l, &arr[0]);
  l = cdlist_push_back(l, &arr[1]);
  l = cdlist_push_back(l, &arr[2]);
  CTEST_COND("cdlist_push_back", *(int*)cdlist_back(l) == 3);

  l = cdlist_push_front(l, &arr[0]);
  CTEST_COND("cdlist_push_front", *(int*)cdlist_front(l) == 1);

  cdlist_pop_back(l);
  CTEST_COND("cdlist_pop_back", *(int*)cdlist_back(l) == 2);

  cdlist_pop_front(l);
  CTEST_COND("cdlist_pop_front", *(int*)cdlist_front(l) == 1);

  cdlist_free(l);
  CTEST_END();
}

int main(int argc, char* argv[]) {
  test_cdlist();
  exit(EXIT_SUCCESS);
}