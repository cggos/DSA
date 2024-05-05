// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/**
 * @file mem_align.cpp
 * @author Gavin Gao (cggos@outlook.com)
 * @brief
 * @details
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

#pragma pack(4)  // 设定为n字节对齐

struct A {
  int a;   // 内存位置：[0]..[3]
  char b;  // 内存位置：[4]
  int *c;  // 内存位置：[8]..[15]
};

struct B0 {
  char a;
  int b;
  short c;
};

struct B1 {
  char a;
  short c;
  int b;
};

struct C {
  char a;
  short c;
  long b;
} __attribute__((packed));

int main() {
  std::cout << "ptr: " << sizeof(int *) << std::endl;

  std::cout << "A: " << sizeof(A) << std::endl;
  std::cout << "B0: " << sizeof(B0) << std::endl;
  std::cout << "B1: " << sizeof(B1) << std::endl;
  std::cout << "C: " << sizeof(C) << std::endl;
  C c;
  std::cout << "c: " << sizeof(c) << std::endl;

  A obj;
  std::cout << "addr of a: " << static_cast<void *>(&obj.a) << std::endl;
  std::cout << "addr of b: " << static_cast<void *>(&obj.b) << std::endl;
  std::cout << "addr of c: " << static_cast<void *>(&obj.c) << std::endl;

  return 0;
}
