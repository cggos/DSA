#ifndef CGADS_LINEAR_LIST_SINGLE__H_
#define CGADS_LINEAR_LIST_SINGLE__H_

#ifdef __cplusplus
extern "C" {
#endif

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;
typedef struct Node *LinkList; /* 定义LinkList */

Status visit(ElemType c);

Status InitList(LinkList *L);

int ListLength(LinkList L);

Status ListTraverse(LinkList L);

void CreateListTail(LinkList *L, int n);

void SelectSort0(LinkList list);

LinkList SelectSort2(LinkList L);

LinkList SelectSort1(LinkList L);

#ifdef __cplusplus
}
#endif

#endif  // CGADS_LINEAR_LIST_SINGLE__H_