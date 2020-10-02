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

bool IsEmpty(LinkedList *L) {  //判断表是否为空的函数
    return L->size?false:true;
}

int NextNode(LinkedList *L) {  //将后继结点设置为当前结点的函数
    //若当前结点存在，则将其后继结点设为当前结点
    if(L->position>=0 && L->position<L->size) {
        L->position++;
        L->prevPtr = L->currPtr;
        L->currPtr = (L->currPtr)->next;
    } else {
        L->position = L->size;
    }
    return L->position;
}

int SetPosition(LinkedList *L, int pos) { //重置链表当前结点位置的函数
    if(!L->size) return -1;  //链表为空
    if(pos<0 || pos>L->size-1) {
        cout << "position error!" << endl;
        return -1;
    }
    //寻找对应结点
    L->currPtr = L->front;
    L->prevPtr = NULL;
    L->position = 0;
    for(int i = 0; i < pos; i++) {
        L->position++;
        L->prevPtr = L->currPtr;
        L->currPtr = (L->currPtr)->next;
    }
    return L->position;  //返回当前结点位置
}
void InsertAt(LinkedList *L, ElementType item) { //链表中在当前结点处插入新结点的函数
    Node *newNode;
    if(!L->size) {
        newNode = GetNode(item,L->front); //在空表中插入
        L->front = newNode;
        L->rear = newNode;
        L->position = 0;
    } else if(!L->prevPtr) {
        newNode = GetNode(item,L->front);  //在表头结点插入
        L->front = newNode;
    } else {
        newNode = GetNode(item,L->currPtr);  //在链表中间插入
        InsertAfter(L->prevPtr,newNode);
    }
    L->size++;   //增加链表的大小
    L->currPtr = newNode;   //新插入的结点作为当前结点
}

void InsertAfter(LinkedList *L, ElementType item) {  //链表中在当前结点后插入新结点的函数
    Node *newNode;
    if(!L->size) {
        newNode = GetNode(item,NULL); //在空表中插入
        L->front = newNode;
        L->rear = newNode;
        L->position = 0;
    } else if(!L->currPtr || L->currPtr==L->rear) {
        newNode = GetNode(item,NULL);  //在表头结点插入
        InsertAfter(L->rear,newNode);
        L->prevPtr = L->rear;
        L->rear = newNode;
        L->position = L->size;
    } else {
        newNode = GetNode(item,(L->currPtr)->next);  //在链表中间插入
        InsertAfter(L->currPtr,newNode);
        L->prevPtr = L->currPtr;
        L->position++;
    }
    L->size++;   //增加链表的大小
    L->currPtr = newNode;   //新插入的结点作为当前结点
}

void DeleteAt(LinkedList *L) { //链表中删除当前结点的函数
    Node *oldNode;
    if(!L->currPtr) {   //若表为空或已到表尾，则给出错误提示并返回
        cout << "DeleteAt: current position is invalid!" << endl;
        return ;
    }
    if(!L->prevPtr) {   //若删除的是表头结点
        oldNode = L->front;
        L->front = (L->currPtr)->next;
    } else {   //若删除的是表中结点
        oldNode = DeleteAfter(L->prevPtr);
    }
    if(oldNode == L->rear) {  //若删除的是表未结点，则修改表尾指针
        L->rear = L->prevPtr;
    }
    L->currPtr = oldNode->next;   //新插入的结点作为当前结点
    FreeNode(oldNode);   //释放原当前结点
    L->size--;   //修改链表的大小
}

void DeleteAfter(LinkedList *L) {  //链表中删除当前结点的后继结点的函数
    Node *oldNode;
    if(!L->currPtr || L->currPtr==L->rear) {   //若表为空或已到表尾，则给出错误提示并返回
        cout << "DeleteAfter: current position is invalid!" << endl;
        return ;
    }
    oldNode = DeleteAfter(L->currPtr);  //保存被删除结点的指针并从来链表中删除该结点
    if(oldNode == L->rear) {  //若删除的是表未结点，则修改表尾指针
        L->rear = L->currPtr;
    }
    FreeNode(oldNode);   //释放原当前结点
    L->size--;   //修改链表的大小
}

ElementType GetData(LinkedList *L) {  //链表中获取当前结点数据的函数
    if(!L->size || !L->currPtr) {
        cout << "Data: current node not exist!" << endl;
        exit(1);
    }
    return (L->currPtr)->data;
}

void SetData(LinkedList *L,ElementType item) {  //链表中修改当前结点数据的函数
    if(!L->size || !L->currPtr) {  //若表为空或已达到表尾，则出错
        cout << "Data: current node not exist!" << endl;
        exit(1);
    }
    (L->currPtr)->data = item;
}

void Clear(LinkedList *L) {   //链表中清空链表的函数
    Node *currNode = L->front;
    Node *nextNode;
    while(currNode) {
        nextNode = currNode->next;  //保存后继结点指针
        FreeNode(currNode);  //释放当前结点
        currNode = nextNode;  //原后继结点成为当前结点
    }
    //修改空链表数据
    L->front = NULL;
    L->rear = NULL;
    L->prevPtr = NULL;
    L->currPtr = NULL;
    L->size = 0;
    L->position = -1;
}