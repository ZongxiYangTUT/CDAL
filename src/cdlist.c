// Copyright (c) 2025 Zongxi Yang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "cdlist.h"

#include <stdlib.h>

static bool is_invalid(cdlist* l) { return l == NULL; }

cdlist* cdlist_create(void) {
  cdlist* l = malloc(sizeof(cdlist));
  if (l == NULL) return NULL;
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
  l->free = NULL;
  l->copy = NULL;
  l->equal = NULL;
  return l;
}

void cdlist_free(cdlist* l) {
  if (is_invalid(l)) return;
  cdlist_node* curr = l->head;
  while (curr) {
    cdlist_node* nxt = curr->next;
    if (l->free != NULL) l->free(curr->value);
    free(curr);
    curr = nxt;
  }
  free(l);
}

size_t cdlist_size(cdlist* l) {
  if (is_invalid(l)) return 0;
  return l->size;
}

void* cdlist_value(cdlist_node* node) {
  if (node == NULL) return NULL;
  return node->value;
}

void cdlist_set_free(cdlist* l, void (*free)(void* val)) {
  if (is_invalid(l)) return;
  l->free = free;
}

void cdlist_set_copy(cdlist* l, void* (*copy)(void* val)) {
  if (is_invalid(l)) return;
  l->copy = copy;
}

void cdlist_set_equal(cdlist* l, bool (*equal)(void* v1, void* v2)) {
  if (is_invalid(l)) return;
  l->equal = equal;
}

cdlist* cdlist_push_back(cdlist* l, void* val) {
  if (is_invalid(l)) return NULL;
  cdlist_node* new_node = malloc(sizeof(cdlist_node));
  if (new_node == NULL) return NULL;
  new_node->value = val;
  new_node->next = NULL;
  if (l->tail == NULL) {
    new_node->prev = NULL;
    l->tail = new_node;
    l->head = new_node;
  } else {
    new_node->prev = l->tail;
    l->tail->next = new_node;
    l->tail = new_node;
  }
  l->size++;
  return l;
}

cdlist* cdlist_push_front(cdlist* l, void* val) {
  if (is_invalid(l)) return NULL;
  cdlist_node* new_node = malloc(sizeof(cdlist_node));
  if (new_node == NULL) return NULL;
  new_node->value = val;
  new_node->prev = NULL;
  if (l->head == NULL) {
    new_node->next = NULL;
    l->head = new_node;
    l->tail = new_node;
  } else {
    new_node->next = l->head;
    l->head->prev = new_node;
    l->head = new_node;
  }
  l->size++;
  return l;
}

void* cdlist_back(cdlist* l) {
  if (is_invalid(l)) return NULL;
  if (l->size == 0) return NULL;
  return l->tail->value;
}

void* cdlist_front(cdlist* l) {
  if (is_invalid(l)) return NULL;
  if (l->size == 0) return NULL;
  return l->head->value;
}

void cdlist_pop_back(cdlist* l) {
  if (is_invalid(l)) return;
  if (l->size == 0) return;
  cdlist_node* tmp = l->tail;
  if (l->size == 1) {
    l->head = l->tail = NULL;
  } else {
    l->tail = tmp->prev;
    l->tail->next = NULL;
  }
  if (l->free) {
    l->free(tmp->value);
  }
  free(tmp);
  l->size--;
}

void cdlist_pop_front(cdlist* l) {
  if (is_invalid(l)) return;
  if (l->size == 0) return;
  cdlist_node* tmp = l->head;

  if (l->size == 1) {
    l->head = l->tail = NULL;
  } else {
    l->head = tmp->next;
    l->head->prev = NULL;
  }
  if (l->free) {
    l->free(tmp->value);
  }
  free(tmp);
  l->size--;
}

cdlist* cdlist_insert(cdlist* l, cdlist_node* insert_pos, void* val) {
  if (is_invalid(l)) return NULL;
  if (insert_pos == NULL) return NULL;

  if (insert_pos == l->head) {
    return cdlist_push_front(l, val);
  }

  cdlist_node* new_node = malloc(sizeof(cdlist_node));
  if (new_node == NULL) return l;
  new_node->value = val;

  cdlist_node* prev = insert_pos->prev;
  insert_pos->prev = new_node;
  prev->next = new_node;
  new_node->next = insert_pos;
  new_node->prev = prev;
  l->size++;
  return l;
}

void cdlist_remove(cdlist* l, cdlist_node* node) {
  if (is_invalid(l)) return;
  if (node == NULL) return;
  if (l->size == 0) return;

  if (node == l->head) {
    cdlist_pop_front(l);
    return;
  }

  if (node == l->tail) {
    cdlist_pop_back(l);
    return;
  }

  cdlist_node* prev = node->prev;
  cdlist_node* next = node->next;
  if (l->free) {
    l->free(node->value);
  }
  free(node);
  prev->next = next;
  next->prev = prev;

  l->size--;
}

cdlist_node* cdlist_find(cdlist* l, void* val) {
  if (is_invalid(l)) return NULL;
  cdlist_node* curr = l->head;
  while (curr) {
    if (l->equal) {
      if (l->equal(curr->value, val)) return curr;
    } else {
      if (curr->value == val) return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

cdlist_node* cdlist_get(cdlist* l, size_t index) {
  if (is_invalid(l)) return NULL;
  if (index >= l->size) return NULL;
  cdlist_node* curr = l->head;
  while (index--) {
    curr = curr->next;
  }
  return curr;
}

cdlist_iterator cdlist_begin(cdlist* l) {
  cdlist_iterator iter;
  if (is_invalid(l)) return iter;
  iter.dir = 0;
  iter.node = l->head;
  return iter;
}

cdlist_iterator cdlist_rbegin(cdlist* l) {
  cdlist_iterator iter;
  if (is_invalid(l)) return iter;
  iter.dir = 1;
  iter.node = l->tail;
  return iter;
}

cdlist_node* cdlist_next(cdlist_iterator* iter) {
  if (iter == NULL) return NULL;
  cdlist_node* curr = iter->node;
  if (curr != NULL) {
    if (iter->dir == 0)
      iter->node = curr->next;
    else
      iter->node = curr->prev;
  }
  return curr;
}

void cdlist_reverse(cdlist* l) {
  if (is_invalid(l)) return;
  cdlist_node* tmp = l->head;
  l->head = l->tail;
  l->tail = tmp;
}