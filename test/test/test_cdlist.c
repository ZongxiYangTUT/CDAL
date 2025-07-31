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

  cdlist_node* node = cdlist_find(l, &arr[1]);
  CTEST_COND("cdlist_find", *(int*)node->value == 2);
  cdlist_insert(l, node, &arr[0]);

  CTEST_COND("cdlist_size", cdlist_size(l) == 3);
  node = cdlist_get(l, 0);

  CTEST_COND("cdlist_insert", *(int*)node->value == 1);

  cdlist_iterator iter = cdlist_begin(l);

  while ((node = cdlist_next(&iter)) != NULL) {
    printf("%d\n", *(int*)cdlist_value(node));
  }

  cdlist_free(l);
  CTEST_END();
}

int main(int argc, char* argv[]) {
  test_cdlist();
  exit(EXIT_SUCCESS);
}