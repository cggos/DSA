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

#ifndef CGADS_QUEUE_H_
#define CGADS_QUEUE_H_

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

#endif  // CGADS_QUEUE_H_
