#include "TianQin.h"

using namespace std;

void createListL(LNode *&C, int a[], int n) { //头插法建立链表
    LNode *s;
    C = (LNode*)malloc(sizeof(LNode));
    C->next = NULL;
    for(int i = 0; i < n; ++i) {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = a[i];
        //下面两句是头插法的关键步骤
        s->next = C->next;   //s所指新结点的指针域next指向C中开始的结点
        C->next = s;    //头结点的指针域next指向s结点，使得s成为新开始的结点
    }
}
void createListR(LNode *&C, int a[], int n) { //尾插法建立链表
    LNode *s,*r;  //s用来指向新申请的结点
    C = (LNode*)malloc(sizeof(LNode));
    C->next = NULL;
    r = C; //r指向头结点，因为此时头结点就是终端结点
    for(int i = 0; i < n; i++) {
        s = (LNode*)malloc(sizeof(LNode));  //s指向新申请的结点
        s->data = a[i];   //新申请的结点用来接收数组a中的元素
        //尾插法关键语句
        r->next = s;      //用r来接受新的结点
        r = r->next;      //r指向终端结点，以便于接纳下一个结点
    }
    r->next = NULL;
}

void createDListR(DLNode *&L, int a[], int n) { //尾插法建立双链表
    DLNode *s,*r;
    L = (DLNode*)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;  //和单链表一样，r始终指向终端结点，此时头结点即终端结点
    for(int i = 0; i < n; ++i) {
        s = (DLNode*)malloc(sizeof(DLNode));  //创建新结点
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}