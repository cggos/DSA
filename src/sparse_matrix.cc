/*
 * Filename: sparse_matrix.cc
 * Created Date: Saturday, March 14th 2020, 10:47:55 pm
 * Author: cggos
 *
 * Copyright (c) 2020 Your Company
 *
 * 利用三元组实现稀疏矩阵的压缩存储，并在此基础上进行转置和相加操作
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define N 30  //所含非零元素的最大个数
#pragma warning(disable : 4996)

typedef struct mytripple  //三元组
{
  int i, j;
  int data;
} TR;

typedef struct mymatrix  //稀疏矩阵
{
  TR T[N];         //三元组
  int mu, nu, tu;  //行数，列数，非零元素个数
} MA;

void init(MA *A, MA *B);  //初始化矩阵A,B
void showMatrix(MA *A);   //显示矩阵A
MA reverse(MA *A);        //转置矩阵A，返回转置后的矩阵，时间复杂度O(tu+nu)
MA addition(MA *A, MA *B);  //将矩阵A,B相加，返回和，相当于有序链表的合并，时间复杂度O(A->tu+B->tu)

int main() {
  MA A, B, C;
  init(&A, &B);
  showMatrix(&A);
  showMatrix(&B);

  C = reverse(&B);
  showMatrix(&C);

  C = addition(&A, &B);
  showMatrix(&C);

  return 0;
}

void init(MA *A, MA *B) {
  A->mu = 3;
  A->nu = 4;
  A->tu = 4;
  A->T[1].data = 3;
  A->T[1].i = 1;
  A->T[1].j = 2;
  A->T[2].data = -1;
  A->T[2].i = 2;
  A->T[2].j = 2;
  A->T[3].data = 12;
  A->T[3].i = 2;
  A->T[3].j = 4;
  A->T[4].data = 9;
  A->T[4].i = 3;
  A->T[4].j = 1;
  ///////////////////////////////////////////////////////////////////
  B->mu = 3;
  B->nu = 4;
  B->tu = 5;
  B->T[1].data = 4;
  B->T[1].i = 1;
  B->T[1].j = 4;
  B->T[2].data = 1;
  B->T[2].i = 2;
  B->T[2].j = 2;
  B->T[3].data = 5;
  B->T[3].i = 2;
  B->T[3].j = 3;
  B->T[4].data = 2;
  B->T[4].i = 3;
  B->T[4].j = 1;
  B->T[5].data = -6;
  B->T[5].i = 3;
  B->T[5].j = 2;
}

void showMatrix(MA *A) {
  int i, j, k;  // i表示行号，j表示列号，k表示三元组中非零元的序号
  k = 1;
  for (i = 1; i <= A->mu; i++) {
    for (j = 1; j <= A->nu; j++) {
      if (i == A->T[k].i && j == A->T[k].j) {
        printf("%4d", A->T[k].data);
        k++;
      } else
        printf("%4d", 0);
    }
    printf("\n");
  }
  printf("\n");
}

MA reverse(MA *A)  //转置矩阵A，返回转置后的矩阵
{
  int i;
  int pos;
  TR temp;
  int *cpos, *cnum;  //建立列逻辑链接
  MA B;
  cnum = (int *)malloc((A->nu + 1) * sizeof(int));
  cpos = (int *)malloc((A->nu + 1) * sizeof(int));
  //初始化cnum
  for (i = 1; i <= A->nu; i++) cnum[i] = 0;
  for (i = 1; i <= A->tu; i++) cnum[A->T[i].j]++;

  //设置cpos
  cpos[1] = 1;
  for (i = 2; i <= A->nu; i++) cpos[i] = cpos[i - 1] + cnum[i - 1];
  free(cnum);

  //前期准备工作结束，准备转置
  B.mu = A->nu;
  B.nu = A->mu;
  B.tu = A->tu;
  //利用cpos进行放置
  for (i = 1; i <= A->tu; i++) {
    temp = A->T[i];
    pos = cpos[temp.j];
    B.T[pos].i = temp.j;
    B.T[pos].j = temp.i;
    B.T[pos].data = temp.data;
    cpos[temp.j]++;
  }

  free(cpos);
  return B;
}

MA addition(MA *A, MA *B)  //将矩阵A,B相加，返回和
{
  int i, j, k;  //计数器
  int temp;
  int p1, p2;  //相应元素在A,B中的位置
  int mu, nu;
  MA C;

  mu = A->mu;
  nu = A->nu;
  C.mu = mu;
  C.nu = nu;

  k = 0;                                         //表示C中非零元素个数
  for (i = 1, j = 1; i <= A->tu && j <= B->tu;)  //比较过程
  {
    p1 = (A->T[i].i - 1) * nu + A->T[i].j;
    p2 = (B->T[j].i - 1) * nu + B->T[j].j;
    if (p1 < p2) {
      k++;
      C.T[k] = A->T[i];
      i++;
    } else if (p2 < p1) {
      k++;
      C.T[k] = B->T[j];
      j++;
    } else  // p1==p2
    {
      temp = A->T[i].data + B->T[j].data;
      if (temp != 0)  //如果元素之和不为0，将其放到C中
      {
        k++;
        C.T[k].i = A->T[i].i;
        C.T[k].j = A->T[i].j;
        C.T[k].data = temp;
      }
      i++;
      j++;
    }
  }
  //比较过程结束之后，将剩余元素转移到C中
  while (i <= A->tu) {
    k++;
    C.T[k] = A->T[i];
    i++;
  }
  while (j <= B->tu) {
    k++;
    C.T[k] = B->T[j];
    j++;
  }
  //设置C的非零元素个数
  C.tu = k;
  return C;
}
