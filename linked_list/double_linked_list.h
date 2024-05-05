// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

/**
 * @file linked_list_double.h
 * @author Gavin Gao (cggos@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef DSA_LINKED_LIST_DOUBLE_H_
#define DSA_LINKED_LIST_DOUBLE_H_

namespace cg {

typedef int _T;

class DoubleLinkedList {
 private:
  typedef struct Node {
    _T data;
    Node* last;
    Node* next;
    Node() : last(nullptr), next(nullptr) {}
  } Node;

 public:
  DoubleLinkedList();
  ~DoubleLinkedList();

  bool empty() const;
  int size() const;

  Node* make_node();

  _T front() const;
  _T back() const;

  void push_front(const _T& data);
  void push_back(const _T& data);

 private:
  Node* head_;
  Node* tail_;
};

};  // namespace cg

#endif  // DSA_LINKED_LIST_DOUBLE_H_