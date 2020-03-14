#include <stdio.h>
#include <iostream>

#include "cgads/tree_binary.h"

//打印二叉树中一个节点的所有祖先节点
void Ancestor(BTREE tree, int item)
{
    BTREE STACK1[100], p=tree;
    int STACK2[100], top=-1, flag;
    if(tree!=nullptr && tree->data!=item)
    {
        do
        {
            while(p!=nullptr)
            {
                STACK1[++top] = p;
                STACK2[top] = 0;
                p=p->lchild;
            }

            p = STACK1[top];
            flag = STACK2[top--];

            if(flag==0)
            {
                STACK1[++top] = p;
                STACK2[top] = 1;
                p=p->rchild;
            }
            else
            {
                if(p->data==item)
                {
                    while(top!=-1)
                    {
                        printf("%4d", STACK1[top--]->data);
                    }
                    break;
                }
                else
                {
                    p = nullptr;
                }
            }

        }while(!(p==nullptr&&top==-1));
    }
}

//===============================================先序递归遍历二叉树
void PreOrderTraverse(BTREE &T) {
    //先序递归遍历二叉树
    if(T){//当结点不为空的时候执行
        std::cout<<T->data;
        PreOrderTraverse(T->lchild);//
        PreOrderTraverse(T->rchild);
    }
    else
        std::cout<<"";
}//PreOrderTraverse

//================================================中序遍历二叉树
void Inorder(BTREE &T) {//中序递归遍历二叉树
    if(T){//bt=null退层
        Inorder(T->lchild);//中序遍历左子树
        std::cout<<T->data;//访问参数
        Inorder(T->rchild);//中序遍历右子树
    }
    else
        std::cout<<"";
}//Inorder

//=================================================后序递归遍历二叉树
void Posorder(BTREE &T) {
    if(T){
        Posorder(T->lchild);//后序递归遍历左子树
        Posorder(T->rchild);//后序递归遍历右子树
        std::cout<<T->data;//访问根结点
    }
    else
        std::cout<<"";
}
