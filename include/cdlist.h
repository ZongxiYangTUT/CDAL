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
#ifndef CDOUBLELIST_H
#define CDOUBLELIST_H
#include <stdbool.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct cdlist_node {
  struct cdlist_node* prev;
  struct cdlist_node* next;
  void* value;
} cdlist_node;

typedef struct {
  cdlist_node* node;
  int dir;  ///< 0: forward 1: reverse
} cdlist_iterator;

typedef struct {
  cdlist_node* head;
  cdlist_node* tail;
  size_t size;
  void (*free)(void* val);
  void* (*copy)(void* val);
  bool (*equal)(void* v1, void* v2);
} cdlist;

cdlist* cdlist_create(void);

void cdlist_free(cdlist* l);

size_t cdlist_size(cdlist* l);

void* cdlist_value(cdlist_node* node);

void cdlist_set_free(cdlist* l, void (*free)(void* val));

void cdlist_set_copy(cdlist* l, void* (*copy)(void* val));

void cdlist_set_equal(cdlist* l, bool (*equal)(void* v1, void* v2));

cdlist* cdlist_push_back(cdlist* l, void* val);

cdlist* cdlist_push_front(cdlist* l, void* val);

void* cdlist_back(cdlist* l);

void* cdlist_front(cdlist* l);

void cdlist_pop_back(cdlist* l);

void cdlist_pop_front(cdlist* l);

cdlist* cdlist_insert(cdlist* l, cdlist_node* insert_pos, void* val);

void cdlist_remove(cdlist* l, cdlist_node* node);

cdlist_node* cdlist_find(cdlist* l, void* val);

cdlist_node* cdlist_get(cdlist* l, size_t index);

cdlist_iterator cdlist_begin(cdlist* l);

cdlist_iterator cdlist_rbegin(cdlist* l);

cdlist_node* cdlist_next(cdlist_iterator* iter);

#ifdef __cplusplus
}
#endif

#endif  // CDOUBLELIST_H