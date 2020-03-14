#include <iostream>

#include <gtest/gtest.h>

#include "cgads/algorithm.h"
#include "cgads/linear_list.h"
#include "cgads/linear_list_single.h"

TEST(Algorithm, basis)
{
    std::cout << world_length() << std::endl;

    // test7();
}

TEST(LinearList, methods)
{
    LinearList<int> ll;
    ll.insert(0, 5);
    std::cout << ll.single_list_->next->data << std::endl;

    {
        LinkList L;
        char opp;

        InitList(&L);
        printf("初始化L后：ListLength(L)=%d\n",ListLength(L));

        printf("\n1.查看链表 \n2.创建链表（尾插法） \n3.链表长度 \n4.交换两个结点 \n0.退出 \n请选择你的操作：\n");
        while(opp != '0') {
            scanf("%c",&opp);
            switch(opp) {
            case '1':
                ListTraverse(L);
                printf("\n");
                break;
            case '2':
                CreateListTail(&L,10);
                printf("整体创建L的元素(尾插法)：\n");
                ListTraverse(L);
                printf("\n");
                break;
            case '3':
                //clearList(pHead);   //清空链表
                printf("ListLength(L)=%d \n",ListLength(L));
                printf("\n");
                break;
            case '4':
                L = SelectSort2(L);
                //printf("%d \n", find);
                ListTraverse(L);
                printf("\n");
                break;
            case '0':
                exit(0);
            }
        }
    }
}
