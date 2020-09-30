#ifndef INC_821DATA_STRUCTURES_LINKEDLIST_H
#define INC_821DATA_STRUCTURES_LINKEDLIST_H
#include <bits/stdc++.h>
#include "node.h"

typedef enum boolean {FALSE,TRUE} Bool;  //类似C++的bool型

typedef struct linkedList {      //单链表结构
    Node *front, *rear;  //指向表头和表尾的结点
    Node *prevPtr, currPtr;  //用于访问数据、插入和删除结点的指针
    int size;        //表中的结点数
    int position;    //表中当前结点位置计数
}LinkedList;

Node *GetNode(ElementType item, Node *ptr);   //申请结点空间的函数
void FreeNode(Node *ptr);  //释放结点空间的函数
void InitLinkedList(LinkedList *L);  //单链表初始化函数
bool IsEmpty(LinkedList *L);  //判断表是否为空的函数
int NextNode(LinkedList *L);  //将后继结点设置为当前结点的函数
int SetPosition(LinkedList *L, int pos); //重置链表当前结点位置的函数
void InsertAt(LinkedList *L, ElementType item); //链表中在当前结点处插入新结点的函数
void InsertAfter(LinkedList *L, ElementType item);  //链表中在当前结点后插入新结点的函数
void DeleteAt(LinkedList *L); //链表中删除当前结点的函数
void DeleteAfter(LinkedList *L);  //链表中删除当前结点的后继结点的函数
ElementType GetData(LinkedList *L);  //链表中获取当前结点数据的函数
void SetData(LinkedList *L,ElementType item);  //链表中修改当前结点数据的函数
void Clear(LinkedList *L);   //链表中清空链表的函数

#endif //INC_821DATA_STRUCTURES_LINKEDLIST_H