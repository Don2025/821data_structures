#include "TianQin.h"
using namespace std;
/* P28【例2.3】A和B是两个带头结点的单链表，其中元素递增有序。
 * 设计一个算法，将A和B归并成一个按元素非递减有序的链表C，C由A和B中的结点组成。
 */
void mergeGreaterList(LNode *A,LNode *B,LNode *&C) { //合并成非递减链表
    LNode *p = A->next; //p跟踪A的最小值结点
    LNode *q = B->next; //q跟踪B的最小值结点
    LNode *r;  //r始终指向C的终端结点
    C = A;    //用A的头结点来做C的头结点
    C->next = NULL;
    free(B); //B的头结点已无用，可以释放掉
    r = C;   //r指向C，此时头结点也是终端结点
    while(p!=NULL && q!=NULL) { //当p和q都不为空时，选取两者的最小值
        if(p->data <= q->data) {
            r->next = p;
            p = p->next;
            r = r->next;
        } else {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    //剩余结点的链表链接在C的尾部
    if(p!=NULL) r->next = p;
    if(q!=NULL) r->next = q;
}

void mergeLessList(LNode *A, LNode *B, LNode *&C) {  //合并成非递增链表
    LNode *p = A->next; //p跟踪A的最小值结点
    LNode *q = B->next; //q跟踪B的最小值结点
    LNode *s;  //s始终指向C的终端结点
    C = A;    //用A的头结点来做C的头结点
    C->next = NULL;
    free(B); //B的头结点已无用，可以释放掉
    while(p!=NULL && q!=NULL) { //当p和q都不为空时，选取两者的最小值
        //if-else语句体现了链表的头插法
        if(p->data <= q->data) {
            s = p;
            p = p->next;
            s = C->next;
            C->next = s;
        } else {
            s = q;
            q = q->next;
            s = C->next;
            C->next = s;
        }
    }
    //剩余结点的链表插入到C的头部
    while(p!=NULL) {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while(q!=NULL) {
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
}