#include "linkedstack.h"
using namespace std;

void InitLinkedStack(LinkedStack *LS) {  //初始化函数
    LS->stack = (LinkedList *)malloc(sizeof(LinkedList));
    InitLinkedList(LS->stack);
}

void Push(LinkedStack *LS, ElementType item) {  //入栈
    InsertAt(LS->stack,item);
}

ElementType Pop(LinkedStack *LS) {  //出栈
    ElementType tmpData;
    if(!(LS->stack)->size) { //若栈为空
        cout << "Pop: underflowed!" << endl;
        exit(1);
    }
    tmpData = GetData(LS->stack);
    DeleteAt(LS->stack);
    return tmpData;
}

ElementType Top(LinkedStack *LS) {  //读取栈顶元素
    if(!(LS->stack)->size) { //若栈为空
        cout << "Top: underflowed!" << endl;
        exit(1);
    }
    return GetData(LS->stack);
}