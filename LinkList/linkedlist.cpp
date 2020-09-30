#include "linkedlist.h"
using namespace std;

void InitLinkedList(LinkedList *L) { //单链表初始化函数，建立一个空链表
    L->front = NULL;
    L->rear = NULL;
    L->prevPtr = NULL;
    L->currPtr = NULL;
    L->size = 0;
    L->position = -1;
}

Node *GetNode(ElementType item, Node *ptr) { //申请结点空间的函数

}

void FreeNode(Node *ptr) { //释放结点空间的函数

}