#include "mix/queue.h"

template <typename T>
void CQueue<T>::appendTail(const T &element) {
  while (!stack2.empty()) {
    T &data = stack2.top();
    stack1.push(data);
    stack2.pop();
  }
  stack1.push(element);
}

template <typename T>
void CQueue<T>::deleteHead() {
  if (stack2.empty()) {
    while (!stack1.empty()) {
      T &data = stack1.top();
      stack2.push(data);
      stack1.pop();
    }
  }
  if (stack2.empty()) std::cerr << "Queue is EMPTY!" << std::endl;
  stack2.pop();
}
