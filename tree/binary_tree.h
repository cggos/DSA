// Copyright 2024 Gavin Gao. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef DSA_TREE_BINARY__H_
#define DSA_TREE_BINARY__H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct node {
  int data;
  struct node *lchild, *rchild;
} * BTREE;

void Ancestor(BTREE tree, int item);

void PreOrderTraverse(BTREE &T);

void Inorder(BTREE &T);

void Posorder(BTREE &T);

#ifdef __cplusplus
}
#endif

#endif  // DSA_TREE_BINARY__H_