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

#include "cstring.h"

#include <stdlib.h>
#include <string.h>
#define GET_HEADER(s) ((cstring_header*)((s) - sizeof(cstring_header)))

typedef struct {
  size_t len;
  size_t free;
  char buf[];
} cstring_header;

size_t cstring_len(cstring s) {
  cstring_header* hdr = GET_HEADER(s);
  return hdr->len;
}

size_t cstring_avail(cstring s) {
  cstring_header* hdr = GET_HEADER(s);
  return hdr->free;
}

cstring cstring_newlen(const void* data, size_t len) {
  if (!data) return NULL;

  cstring_header* hdr = malloc(sizeof(cstring_header) + len + 1);
  if (!hdr) return NULL;

  memcpy(hdr->buf, data, len);

  hdr->len = len;
  hdr->free = 0;
  hdr->buf[len] = '\0';
  return hdr->buf;
}

cstring cstring_newstr(const char* s) { return cstring_newlen(s, strlen(s)); }

void cstring_clear(cstring s) {
  if (!s) return;
  cstring_header* hdr = GET_HEADER(s);
  hdr->free = 0;
  hdr->len = 0;
  free(hdr);
}