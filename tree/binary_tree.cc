#include "tree/binary_tree.h"

#include <stdio.h>

#include <iostream>

//打印二叉树中一个节点的所有祖先节点
void Ancestor(BTREE tree, int item) {
  BTREE STACK1[100], p = tree;
  int STACK2[100], top = -1, flag;
  if (tree != nullptr && tree->data != item) {
    do {
      while (p != nullptr) {
        STACK1[++top] = p;
        STACK2[top] = 0;
        p = p->lchild;
      }

      p = STACK1[top];
      flag = STACK2[top--];

      if (flag == 0) {
        STACK1[++top] = p;
        STACK2[top] = 1;
        p = p->rchild;
      } else {
        if (p->data == item) {
          while (top != -1) {
            printf("%4d", STACK1[top--]->data);
          }
          break;
        } else {
          p = nullptr;
        }
      }

    } while (!(p == nullptr && top == -1));
  }
}

//===============================================先序递归遍历二叉树
void PreOrderTraverse(BTREE &T) {
  if (T) {
    std::cout << T->data;
    PreOrderTraverse(T->lchild);  //
    PreOrderTraverse(T->rchild);
  } else
    std::cout << "";
}

//================================================中序遍历二叉树
void Inorder(BTREE &T) {
  if (T) {
    Inorder(T->lchild);
    std::cout << T->data;
    Inorder(T->rchild);
  } else
    std::cout << "";
}

//=================================================后序递归遍历二叉树
void Posorder(BTREE &T) {
  if (T) {
    Posorder(T->lchild);
    Posorder(T->rchild);
    std::cout << T->data;
  } else
    std::cout << "";
}
