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

#ifndef CSTRING_H
#define CSTRING_H
#include <stdbool.h>
#include <stddef.h>
typedef char* cstring;

size_t cstring_len(cstring s);

size_t cstring_avail(cstring s);

/// @brief 创建一个以'\0'结尾的字符串，字符串中间可以存储'\0'，如
/// cstring_newlen("hello\0world", 11); 是可以的
/// @param data
/// @param len
/// @return
cstring cstring_newlen(const void* data, size_t len);

cstring cstring_empty(void);

cstring cstring_newstr(const char* s);

cstring cstring_copy(const cstring s);

bool cstring_equal(const cstring s1, const cstring s2);

char cstring_front(const cstring s);

/// @brief
/// @param s
/// @return 字符串为空时返回'\0'
char cstring_back(const cstring s);

cstring cstring_push_back(cstring s, char ch);

cstring cstring_catlen(cstring s, const void* data, size_t len);

cstring cstring_cat(cstring s, const char* str);

cstring cstring_catcstring(cstring s, const cstring t);

void cstring_pop_back(cstring s);

/// @brief 将字符串的长度置为0
/// @param s
void cstring_clear(cstring s);

/// @brief 释放字符串申请的空间
/// @param s
void cstring_free(cstring s);

#endif  // CSTRING_H