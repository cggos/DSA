// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <iostream>

#include "linked_list/linked_list_01.h"

int main() {
  ListNode *pHead = NULL;
  ListNode **ppHead = &pHead;

  for (int i = 1; i < 5; ++i) AddToTail(ppHead, i);

  ListNode *pNode = *ppHead;
  while (pNode != NULL) {
    std::cout << pNode->m_nValue << ", ";
    pNode = pNode->m_pNext;
  }
  std::cout << std::endl;

  PrintReversingly_Iteratively(*ppHead);

  PrintReversingly_Recursively(*ppHead);
  std::cout << std::endl;

  return 0;
}