// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/**
 * @file queue.h
 * @author Gavin Gao (cggos@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DSA_QUEUE_H_
#define DSA_QUEUE_H_

#include <iostream>
#include <stack>

template <typename T>
class CQueue {
 public:
  void appendTail(const T &node);
  void deleteHead();

 private:
  std::stack<T> stack1;
  std::stack<T> stack2;
};

#endif  // DSA_QUEUE_H_
