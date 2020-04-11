/**
 * @file codetest_yihang.cpp
 * @author cggos (cggos@outlook.com)
 * @brief 易航智能 笔试题
 * @version 0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <stdlib.h>

using namespace std;

/**************************************************************************************************
    Project 1

    定义一个单向链表node, 每个节点值为int.
    定义函数void create_linklist(…, int n)来生成链表，链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，链表节点值为1,2,3...n；
    定义函数reverse_linklist(...),　对参数传入的链表进行逆转；
    定义函数insert_node(node *pHead, int Index, int Value ), 在指定链表位置Index插入指定Value；
    定义函数delete_node(node *pHead,  int Index),删除链表位置Index所在的节点；
    定义函数delete_linklist(),　删除整个链表；
    定义函数print_linklist(), 打印整个链表。
*/

struct node
{
    int v;
    node* n;
};

/* 链表长度由参数n传入,生成的链表要作为参数返回，而不是当初函数返回值返回，
   链表节点值为1,2,3...n
*/
void create_linklist(node **pHead, int n)
{
}


//对参数传入的链表进行逆转
void reverse_linklist(node **pHead)
{	
}

//在指定链表位置Index插入指定Value
// Index 为 1 ~ n 代表 1 ~ n 个节点
// Index = 0 即为头添加
void insert_node(node **pHead,  int Index, int Value)
{	
}

//删除链表位置Index所在的节点
void delete_node(node **pHead,  int Index)
{	
}

//删除整个链表
void delete_linklist(node **pHead)
{
}

//打印整个列表
void print_linklist(node **pHead)
{
}

/**************************************************************************************************
    Project 2

    假设一只猫一天可能吃1～3只老鼠，编写程序求这只猫在t天内吃掉n只老鼠一共有多少种吃法？
    函数 CountRat():
    Input:
        int t: 时间t天
        int n: 老鼠数量
    return:
        int: 不同吃法总数
*/

int CountRat(int t, int n)
{
}

/**************************************************************************************************
    Project 3

    给定N个二维平面上的点，则在平面上存在无数个矩形可以覆盖这些点，请编写程序求出可覆盖这些点的最小矩形的面积。
    函数rectangle():
    Input:
        double (*data)[2]: 二维点列，为N*2的二维矩阵，第一列表示x坐标，第二列表示y坐标；
        int N: 点的个数。
    return:
        double: 最小矩形的面积。
    注意：题目要求是矩形，而不是圆形或三角形等，矩形可能是长方形或者正方形。点列坐标在main函数中给定。
*/

double rectangle(double (*data)[2], int N)
{
}

/**************************************************************************************************
    Project 4

    给定一个深度小于6层的二叉树，它的每一个非空节点的数值都是整数，且小于16、大于等于0,这样每个节点可以
    表示为一个十六进制字符数组，例如：
            3
          /   \
         5     1
       /  \     \
      7    9     11 
    层数和节点序号都是从0开始计数，也就是第一层为0层，每层第一个节点序号为0.
    这个树中，11这个节点可以用 '23b' 表示，也就是它在第3层的第4个节点，数值是0xb.   
    现给定一系列以此法表示的节点，它们一起组成一个树，并指定其中的任意两个节点，请找出它们最近的共同祖先。
    举例：在这个树中，'207'和'219'的最近共同祖先为'105'，输入'207'和'219'，返回'105'即可。
    '105'和'23b'的最近共同祖先为'003'.
    函数 LCA():
    Input: 
        char (*tree)[3]: 十六进制含义的二维字符数组，为N*3的矩阵，每一行的三个数按顺序依照上述定义；
        int node_size: 树的节点个数；
        char a[3]: 要找最近共同祖先的第一个节点；
        char b[3]: 要找最近共同祖先的第二个节点；
        char lca[3]: 找到的共同祖先节点填充到这个字符数组中。
    return:
        bool: 返回是否成功找到最近共同祖先，true为找到，false为没找到。
    注意：LCA是 lowest common ancestor的缩写。所有节点信息以及需要寻找最近共同祖先的两个节点信息均在main函数中给定。
*/
bool LCA(char (*tree)[3], int node_size, char a[3], char b[3], char lca[3])
{
}

int main()
{
    // Project 1
    // 可将头尾指针及节点个数封装结构体，更方便操作
    cout << "==========Project1=================" << endl;
    node *pHead = nullptr;
    // １．调用create_linklist()生成链表
    create_linklist(&pHead,9);
    print_linklist(&pHead);
    // ２．调用insert_node()插入节点
    insert_node(&pHead,9,10);
    print_linklist(&pHead);
    // ３．调用delete_node()删除节点
    delete_node(&pHead,10);
    print_linklist(&pHead);
    // ４．调用reverse_linklist()逆转
    reverse_linklist(&pHead);
    print_linklist(&pHead);
    
    cout << endl;
    cout << "==========Project1=================" << endl;
    cout << endl;

    // Project 2
    cout << "==========Project2=================" << endl;
    int day = 10;
    int rat_num = 20;
    cout << CountRat(day,rat_num) << " choices to eat " << rat_num << " rats in "
         << day << " days." << endl;
    cout << endl;
    cout << "==========Project2=================" << endl;
    cout << endl;

    // Project 3
    cout << "==========Project3=================" << endl;
    double data[5][2] = {0,0, 1,1, 2,2, 1,3, -1,2};
    cout << "The area of the min rectangle is " << rectangle(data, 5) << endl;
    cout << endl;
    cout << "==========Project3=================" << endl;

    // Project 4
    cout << "==========Project4=================" << endl;
    char tree[][3] = {  '2','0','7',
                        '1','0','5',
                        '3','2','c',
                        '2','1','9',
                        '0','0','3',
                        '1','1','1',
                        '2','3','b',
                        '3','6','4',
                        '3','7','f'};
    char lca[3] = {0};
    char a[3] = {'2','1','9'};
    char b[3] = {'3','7','f'};
    bool found = LCA(tree, 9, a, b, lca);
    if(!found)
        cout << "no lca found." << endl;
    else
        cout << "The lca of a and b is \'" << lca[0] << lca[1] << lca[2] << '\'' << endl;
    cout << endl;
    cout << "==========Project4=================" << endl;
    
    return 0;
}
