#ifndef CGADS_TREE_BINARY__H_
#define CGADS_TREE_BINARY__H_

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

#endif  // CGADS_TREE_BINARY__H_