#include <iostream>

#include "ads/binary_tree_01.h"

LinkQueue CreateQueue() {
  LinkQueue Q;
  Q = (LinkQueue)malloc(sizeof(struct queue));
  Q->front = Q->rear = NULL;
  return Q;
}

void AddQ(LinkQueue Q, BinTree tree) {
  QNode q;
  q = (QNode)malloc(sizeof(struct qNode));
  q->Tree = tree;
  q->Next = NULL;
  if (Q->rear == NULL) {
    Q->front = q;
    Q->rear = q;
  } else {
    Q->rear->Next = q;
    Q->rear = q;
  }
}

BinTree DeleteQ(LinkQueue Q) {
  QNode temp;
  BinTree tree;
  if (Q->front == NULL) return 0;
  if (Q->front == Q->rear) {
    tree = Q->front->Tree;
    Q->front = NULL;
    Q->rear = NULL;
  } else {
    temp = Q->front;
    tree = temp->Tree;
    Q->front = temp->Next;
    free(temp);
  }
  return tree;
}

int IsEmpty(LinkQueue Q) {
  if (Q->front == NULL)
    return 1;
  else
    return 0;
}

BinTree CreateBinTree() {
  int Data;
  BinTree BT, T;
  LinkQueue Q = CreateQueue();  //创建队列
  scanf("%d", &Data);           //根结点数据
  if (Data) {                   //为真，则建结点，入队
    BT = (BinTree)malloc(sizeof(TreeNode));
    BT->Data = Data;
    AddQ(Q, BT);
  } else
    return NULL;         //为0，则返回空树
  while (!IsEmpty(Q)) {  //只要队列不为空，循环就进行
    T = DeleteQ(Q);      //返回队列中第一个结点T地址
    scanf("%d", &Data);  //输入T的左子树数据
    if (!Data)
      T->Left = NULL;  //为0，则T的左子树为空
    else {             //为真，则建T的左子树结点，并将左子树结点地址入队
      T->Left = (BinTree)malloc(sizeof(TreeNode));
      T->Left->Data = Data;
      AddQ(Q, T->Left);
    }
    scanf("%d", &Data);  //输入T的右子树数据
    if (!Data)
      T->Right = NULL;  //为0，则T的右子树为空
    else {              //为真，则建T的右子树结点，并将右子树结点地址入队
      T->Right = (BinTree)malloc(sizeof(TreeNode));
      T->Right->Data = Data;
      AddQ(Q, T->Right);
    }
  }
  return BT;  //循环结束，则返回根结点地址
}

int flag = 1;  //用来输出行末不带空格
void LevelOrderTraversal(BinTree BT) {
  LinkQueue q;
  BinTree T;
  if (!BT) return;       //空树，退出
  q = CreateQueue();     //建队列
  AddQ(q, BT);           //将根结点入队
  while (!IsEmpty(q)) {  //只要队列不为空，循环进行
    T = DeleteQ(q);
    if (flag) {
      printf("%d", T->Data);
      flag = 0;
    } else {
      printf(" %d", T->Data);
    }
    if (T->Left) AddQ(q, T->Left);
    if (T->Right) AddQ(q, T->Right);
  }
}

int main(int argc, char *argv[]) {
  BinTree BT;
  BT = CreateBinTree();
  LevelOrderTraversal(BT);
  return 0;
}
