#include <iostream>
#include "Stack.h"
using namespace std;
//堆栈运算的实现文件Stack.c 我这里直接用的cpp但是不调用cpp的STL

void InitStack(Stack *S,int sz)  //创建栈空间，生成一个空栈
{
    S->MaxSize = sz;
    S->elements = (ElementType *)malloc(sizeof(ElementType)*S->MaxSize);
    S->top = -1;
}

void FreeStack(Stack *S)  //释放栈空间
{
    free(S->elements);
}

bool Push(Stack *S,ElementType x) //入栈
{
    if(!IsFull(S))
    {
        S->elements[++(S->top)] = x;
        return true;
    }
    return false;
}

ElementType Pop(Stack *S)  //出栈
{
    if(!IsEmpty(S))
        return S->elements[(S->top)--];
    else
    {
        cout << "Stack is empty!" << endl;
        exit(1);
    }
}

ElementType GetTop(Stack *S)  //取栈顶的表目
{
    if(!IsEmpty(S))
        return S->elements[S->top];
    else
    {
        cout << "Stack is empty!" << endl;
        exit(1);
    }
}

void Clear(Stack *S)  //栈置空
{
    S->top = -1;
}

bool IsEmpty(Stack *S)  //判断是否为空
{
    return S->top==-1;
}

bool IsFull(Stack *S)  //判断栈是否为满
{
    return S->top==S->MaxSize-1;
}

void StackTestMain()
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    InitStack(S,10);
    for(int i = 10; i < 100; i+=10)
    {
        Push(S,i);
    }
    cout << "The top of stack is:" << GetTop(S) << endl;
    for(int i = 1; i <= 3; i++)
    {
        int x = Pop(S);
    }
    cout << "After triple pop,the top of stack is:" << GetTop(S) << endl;
    Clear(S);
    FreeStack(S);
}