#ifndef INC_821DATA_STRUCTURES_LINKEDSTACK_H
#define INC_821DATA_STRUCTURES_LINKEDSTACK_H
#include "node.h"
#include "linkedlist.h"

typedef struct linkedStack {   //链栈
    LinkedList *stack; //存放栈元素的链表
}LinkedStack;

void InitLinkedStack(LinkedStack *LS);  //初始化函数
void Push(LinkedStack *LS, ElementType item);  //入栈
ElementType Pop(LinkedStack *LS);  //出栈
ElementType Top(LinkedStack *LS);  //读取栈顶元素



#endif //INC_821DATA_STRUCTURES_LINKEDSTACK_H
