#include "TianQin.h"
using namespace std;
/* P79【综合应用题7】 如果允许在循环队列的两端都可以进行插入和删除操作，
 * 要求（1）写出循环队列的类型定义；（2）分别写出从队尾删除和从队头插入的算法。
**/
/*解：本题中涉及了一个操作：Q.front=(Q.front-1+maxSize)%maxSize;
 * 上述语句放在一个循环中，front指针会沿着maxSize-1,maxSize-2,...,2,1,0,maxSize-1,maxSize-2...循环
 * 这条语句的操作和 Q.front=(Q.front+1)%maxSize;实现的效果恰好相反。这两个操作在程序设计题中经常用到。
**/
typedef struct CycQueue {  //循环队列结构定义
    int data[maxSize];
    int front,rear;
}CycQueue;

//出队算法，实现从队尾删除，若删除成功，用x记录删除元素并返回1，否则返回0.
int deQueue(CycQueue &Q, int &x) {
    if(Q.front == Q.rear)
        return 0; //出队失败
    else {
        x = Q.data[Q.rear];
        Q.rear = (Q.rear-1+maxSize)%maxSize; //修改尾指针
        return 1;  //出队成功
    }
}

//入队算法，实现从队首插入元素x
int enQueue(CycQueue &Q, int x) {
    if(Q.rear == (Q.front-1+maxSize)%maxSize) //队满
        return 0;
    else {
        Q.data[Q.front] = x;  //x入队首
        Q.front = (Q.front-1+maxSize)%maxSize; //修改队首指针
        return 1;
    }
}
