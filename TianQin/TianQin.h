#ifndef INC_821DATA_STRUCTURES_TIANQIN_H
#define INC_821DATA_STRUCTURES_TIANQIN_H
#include <bits/stdc++.h>

#define maxSize 100
typedef int ElementType; //定义数据类型
//单链表结点定义
typedef struct LNode {
    ElementType data;   //数据域，存放结点数据
    struct LNode *next; //指针域，指向后继结点
}LNode;
//双链表结点定义
typedef struct DLNode {
    ElementType data;  //数据域，存放结点数据
    struct DLNode *prior; //指向前驱结点的指针
    struct DLNode *next;  //指向后继结点的指针
}DLNode;

void mergeGreaterList(LNode *A, LNode *B, LNode *&C); //例2.3 合并成非递减链表
void mergeLessList(LNode *A, LNode *B, LNode *&C);    //合并成非递增链表
void createListL(LNode *&C, int a[], int n); //头插法建立链表
void createListR(LNode *&C, int a[], int n); //尾插法建立链表
void createDListR(DLNode *&L, int a[], int n); //尾插法建立双链表
#endif //INC_821DATA_STRUCTURES_TIANQIN_H