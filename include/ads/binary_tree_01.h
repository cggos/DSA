/**
 * @file binary_tree_02.cpp
 * @author Gavin Gao (cggos@outlook.com)
 * @brief 二叉树的层序创建&&层序遍历
 *        输入序列为：1，2，3，4，5，6，7，8，0，0，0，0，9，0，0，0，0，0，0
 *        输出序列为：1，2，3，4，5，6，7，8，9
 * @version 0.1
 * @date 2020-04-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef CGADS_BINARY_TREE_01__H_
#define CGADS_BINARY_TREE_01__H_

typedef struct TreeNode {
  int Data;
  TreeNode *Left, *Right;
} * BinTree;

struct qNode {
  BinTree Tree;
  struct qNode *Next;
};
typedef struct qNode *QNode;

struct queue {
  QNode front;
  QNode rear;
};
typedef struct queue *LinkQueue;

LinkQueue CreateQueue();

void AddQ(LinkQueue Q, BinTree tree);

BinTree DeleteQ(LinkQueue Q);

int IsEmpty(LinkQueue Q);

BinTree CreateBinTree();

void LevelOrderTraversal(BinTree BT);

#endif  // CGADS_BINARY_TREE_01__H_