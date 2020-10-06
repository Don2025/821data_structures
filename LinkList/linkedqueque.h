#ifndef INC_821DATA_STRUCTURES_LINKEDQUEQUE_H
#define INC_821DATA_STRUCTURES_LINKEDQUEQUE_H

#include "node.h"
#include "linkedlist.h"

typedef struct linkedQueue {  //队列的链表实现，即链式队列
    LinkedList *queue;
}LinkedQueue;

void InitLinkedQueue(LinkedQueue *LQ);  //初始化链式队列
void InQueue(LinkedQueue *LQ, ElementType item); //入队
ElementType OutQueue(LinkedQueue *LQ);  //出队
ElementType GetFront(LinkedQueue *LQ);   //读取队首元素
void ClearLQ(LinkedQueue *LQ);   //清除队列中的数据元素
bool isEmptyLQ(LinkedQueue *LQ);    //判断链队是否为空

#endif //INC_821DATA_STRUCTURES_LINKEDQUEQUE_H
