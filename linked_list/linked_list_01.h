// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

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

#ifndef DSA_LINKED_LIST_01_H_
#define DSA_LINKED_LIST_01_H_

struct ListNode {
  int m_nValue;
  ListNode *m_pNext;
};

void AddToTail(ListNode **ppHead, int value);

void PrintReversingly_Iteratively(ListNode *pHead);

void PrintReversingly_Recursively(ListNode *pHead);



#endif // DSA_LINKED_LIST_01_H_