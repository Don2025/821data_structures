#include <iostream>
#include "LinearList.h"
using namespace std;

void InitList(LinearList *L,int sz)  //线性表的初始化
{
    if(sz > 0)
    {
        L->MaxSize = sz;
        L->Last = 0;
        L->data = (ElementType *)malloc(sizeof(ElementType)*L->MaxSize);
    }
}

void FreeList(LinearList *L)  //释放线性表的存储空间
{
    free(L->data);
}

bool ListEmpty(LinearList *L)  //判断线性表是否为空
{
    return (L->Last <= 0)?true:false;
}

bool ListFull(LinearList *L)  //判断线性表是否为满
{
    return (L->Last >= L->MaxSize)?true:false;
}

int ListLength(LinearList *L)  //求线性表的长度
{
    return L->Last;
}

ElementType GetElem(LinearList *L,int i)  //取线性表的第i个表目
{
    return (i<0 || i>=L->Last)?NULL:L->data[i];
}

int LocateElem(LinearList *L,ElementType x)  //在线性表中查找x结点
/*查找线性表中值为x的结点，若查找成功返回该结点的序号，否则返回-1
 *若表中值为x的结点有多个，找到的是最前面的一个
**/
{
    int i;
    for(i = 0; i < L->Last; i++)
    {
        if(L->data[i] == x)
            return i;  //查找成功
    }
    return -1;  //查找失败
}

bool InsertElem(LinearList *L,ElementType x,int i)  //在表中第i个位置插入值为x的结点
{
    if(i<0 || i > L->Last || L->Last==L->MaxSize)
        return false;  //插入位置不合理，插入失败
    else
    {
        int j;
        for(j = L->Last-1; j >= i; j--)
            L->data[j+1] = L->data[j];  //后移
        L->data[i] = x;  //插入
        L->Last++;       //表长+1
        return true;     //插入成功
    }
}

bool DeleteElem(LinearList *L,int i)  //删除表中第i个结点
{
    if(i<0 || i > L->Last || L->Last==0)
        return false;  //第i个结点不存在，删除失败
    else
    {
        int j;
        for(j = i; j < L->Last-1; j++)
            L->data[j] = L->data[j+1];  //前移
        L->Last--;  //表长-1
        return true;  //删除成功
    }
}

void printout(LinearList *L)  //打印线性表的表目
{
    int i;
    for(i = 0; i < L->Last; i++)
        cout << (i==0?"":" ") << L->data[i];
    cout << endl;
}

void ListTestMain()
{
    LinearList *L = (LinearList*)malloc(sizeof(LinearList));
    InitList(L,5);
    InsertElem(L,10,0);
    InsertElem(L,20,0);
    InsertElem(L,30,0);
    InsertElem(L,40,0);
    InsertElem(L,50,0);
    if(InsertElem(L,60,0))
        printout(L);
    else if(ListFull(L))
        cout << "List is full, failed to insert." << endl;
    printout(L);
    DeleteElem(L,1);
    DeleteElem(L,1);
    cout << "After twice deletions the list is ";
    printout(L);
    cout << "The location of data 20 is " << LocateElem(L,20) << endl;
    cout << "The 3rd value is " << GetElem(L,2);
    FreeList(L);
}
