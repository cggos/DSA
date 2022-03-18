/**
 * @file linked_list_01.h
 * @author Gavin Gao (cggos@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CGADS_LINKED_LIST_01_H_
#define CGADS_LINKED_LIST_01_H_

struct ListNode {
  int m_nValue;
  ListNode *m_pNext;
};

void AddToTail(ListNode **ppHead, int value);

void PrintReversingly_Iteratively(ListNode *pHead);

void PrintReversingly_Recursively(ListNode *pHead);



#endif // CGADS_LINKED_LIST_01_H_