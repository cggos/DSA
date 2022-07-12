/**
 * @file linked_list_double.cc
 * @author Gavin Gao (cggos@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-03-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "linked_list/double_linked_list.h"

#include <assert.h>

namespace cg {

DoubleLinkedList::DoubleLinkedList() : head_(nullptr), tail_(nullptr) {}

DoubleLinkedList::~DoubleLinkedList() {
  if (!empty()) {
    Node *tmp = head_;
    Node *p;
    while (tmp != nullptr && tmp->next != nullptr) {
      p = tmp;
      tmp = tmp->next;
      delete p;
      p = nullptr;
    }
  }
}

bool DoubleLinkedList::empty() const { return head_ == nullptr || head_->next == nullptr; }

int DoubleLinkedList::size() const {
  if (empty()) return 0;

  int len = 0;
  Node *tmp = new Node;
  tmp = head_;
  while (tmp->next != nullptr && tmp->next != tail_) {
    len++;
    tmp = tmp->next;
  }
  return len;
}

_T DoubleLinkedList::front() const {
  Node *tmp = head_->next;
  assert(tmp == nullptr);
  return tmp->data;
}

_T DoubleLinkedList::back() const {
  Node *tmp = tail_;
  assert(tmp == nullptr);
  return tmp->data;
}

void DoubleLinkedList::push_front(const _T &data) {
  Node *p = new Node;
  p->data = data;
  if (empty()) {
    head_ = new Node;
    tail_ = new Node;
    p->last = head_;
    p->next = tail_;
    head_->last = nullptr;
    head_->next = p;
    tail_->last = p;
    tail_->next = nullptr;
  } else {
    p->next = head_->next;
    head_->next->last = p;

    p->last = head_;
    head_->next = p;
  }
}

void DoubleLinkedList::push_back(const _T &data) {
  Node *p = new Node;
  p->data = data;
  if (empty()) {
    head_ = new Node;
    tail_ = new Node;
    p->last = head_;
    p->next = tail_;
    head_->last = nullptr;
    head_->next = p;
    tail_->last = p;
    tail_->next = nullptr;
  } else {
    tail_->last->next = p;
    p->last = tail_->last;
    tail_->last = p;
    p->next = tail_;
  }
}

}  // namespace cg