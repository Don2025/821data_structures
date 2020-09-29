#ifndef INC_821DATA_STRUCTURES_NODE_H
#define INC_821DATA_STRUCTURES_NODE_H
#include <bits/stdc++.h>

typedef int ElementType;

typedef struct node {   //单链表结点结构
    struct node *next;  //指针域，指向下一结点的指针
    ElementType data;   //数据域，存放当前结点的数值
}Node;

void InitNode(Node *N, ElementType item, Node *ptr);  //初始化单链表结点
void InsertAfter(Node *N, Node *P);   //插入一个单链表结点
Node *DeleteAfter(Node *P);  //删除一个单链表结点
Node *GetNode(ElementType item, Node *nextPtr);   //创建一个单链表结点
void FreeNode(Node *ptr);   //释放一个单链表结点

#endif //INC_821DATA_STRUCTURES_NODE_H
