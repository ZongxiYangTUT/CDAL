#include "chashtable.h"

#include <stdlib.h>
static void init_chash_table(chash_table* cht) {
  cht->table = NULL;
  cht->table = 0;
  cht->used = 0;
}

static void free_chash_table(chash_table* cht) {
  for (size_t i = 0; i < cht->table_size && cht->used > 0; i++) {
    chash_entry* curr = cht->table[i];
    while (curr) {
      chash* nxt = curr->next;
      // TOOD: 析构回调
      free(curr);
      cht->used--;
      curr = nxt;
    }
  }
  free(cht->table);
}

chash* chash_create(void) {
  chash* ht = malloc(sizeof(chash));
  ht->rehashidx = -1;
  init_chash_table(&ht->cht[0]);
  init_chash_table(&ht->cht[1]);
  return ht;
}

bool chash_add(chash* ht, void* key, void* val) {}

bool chash_erase(chash* ht, const void* key) {}

bool chash_resize(chash* ht) {}

void chash_release(chash* ht) {
  free_chash_table(&ht->cht[0]);
  free_chash_table(&ht->cht[1]);
  free(ht);
}
