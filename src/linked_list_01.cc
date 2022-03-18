#include <iostream>
#include <stack>

#include "ads/linked_list_01.h"

void AddToTail(ListNode **ppHead, int value) {
  if (ppHead == NULL) return;

  ListNode *pNew = new ListNode();
  pNew->m_nValue = value;
  pNew->m_pNext = NULL;

  if (*ppHead == NULL)
    *ppHead = pNew;
  else {
    ListNode *pNode = *ppHead;
    while (pNode->m_pNext != NULL) pNode = pNode->m_pNext;

    pNode->m_pNext = pNew;
  }
}

void PrintReversingly_Iteratively(ListNode *pHead) {
  if (pHead == NULL) return;

  std::stack<ListNode *> stackNodes;

  ListNode *pNode = pHead;
  while (pNode != NULL) {
    stackNodes.push(pNode);
    pNode = pNode->m_pNext;
  }

  while (!stackNodes.empty()) {
    pNode = stackNodes.top();
    std::cout << pNode->m_nValue << ", ";
    stackNodes.pop();
  }
  std::cout << std::endl;
}

void PrintReversingly_Recursively(ListNode *pHead) {
  if (pHead == NULL) {
    return;
  }

  if (pHead->m_pNext != NULL) PrintReversingly_Recursively(pHead->m_pNext);

  std::cout << pHead->m_nValue << ", ";
}

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
