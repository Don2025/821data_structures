#ifndef INC_821DATA_STRUCTURES_STACK_H
#define INC_821DATA_STRUCTURES_STACK_H

typedef int ElementType;

typedef struct Stack
{
    int top;  //栈顶指针
    ElementType *elements;  //存放栈元素的数组
    int MaxSize;  //栈空间的最大尺寸
}Stack;

void InitStack(Stack *,int sz);  //创建栈空间，生成一个空栈
void FreeStack(Stack *);  //释放栈空间
bool Push(Stack *,ElementType); //入栈
ElementType Pop(Stack *);  //出栈
ElementType GetTop(Stack *);  //取栈顶的表目
void Clear(Stack *);  //栈置空
bool IsEmpty(Stack *);  //判断是否为空
bool IsFull(Stack *);  //判断栈是否为满
void StackTestMain(void);
#endif //INC_821DATA_STRUCTURES_STACK_H
