#include "node.h"
using namespace std;

void InitNode(Node *N, ElementType item, Node *ptr) { //初始化单链表结点
    N->data = item;
    N->next = ptr;
}

void InsertAfter(Node *N, Node *P) { //在P后面插入一个单链表结点
    P->next = N->next;   //将当前结点的后继结点连接到结点P之后
    N->next = P;         //将结点P作为当前结点的后继结点
}

Node *DeleteAfter(Node *P) {  //删除P后面的一个单链表结点
    Node *ptr = P->next;  //保存当前结点的后继结点
    if(ptr == NULL)
        return NULL;
    P->next = ptr->next;  //当前结点指向原来结点的后继
    return ptr;    //返回指向被删除结点的指针

}

Node *GetNode(ElementType item, Node *nextPtr) { //创建一个单链表结点
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        cout << "Memory allocation failure!" << endl;
        exit(1);
    }
    InitNode(newNode, item, nextPtr);
    return newNode;
}

void FreeNode(Node *ptr) { //释放一个单链表结点
    if(ptr == nullptr) {
        cout << "FreeNode:invalid node pointer!" << endl;
        return ;
    }
    free(ptr);  //释放结点占用的内存空间
}