#include <iostream>
#include "Vector.h"
using namespace std;

void GetArray(Vector *V)  //申请向量的存储空间
{
    V->elements = (ElementType *)malloc(sizeof(ElementType)*V->ArraySize);
    if(V->elements==NULL)
        cout << "Memory Allocation Error!" << endl;
}
void InitVector(Vector *V,int sz)  //初始化空向量，建立一个最大长度为sz的数组
{
    if(sz <= 0)
        cout << "Invalid Array Size!" << endl;
    else
    {
        V->ArraySize = sz;
        V->VectorLength = 0;
        GetArray(V);
    }
}

ElementType GetNode(Vector *V,int i)  //取向量的第i个表目
//取向量中第i个结点的值，若第i个结点存在，则返回该结点的值；否则返回NULL
{
    return (i<0 || i >= V->VectorLength)?NULL:V->elements[i];
}

void FreeVector(Vector *V)  //释放向量的存储空间
{
    free(V->elements);
}

int Find(Vector *V,ElementType x)  //在向量中查找
{
    int i;
    for(i = 0; i < V->VectorLength; i++)
        if(V->elements[i]==x)
            return i;  //找到返回结点序号
    return -1;  //未找到
}

bool Insert(Vector *V,ElementType x,int i)  //在向量第i个位置插入值为x的新结点
{
    if(V->VectorLength == V->ArraySize)  //向量的存储空间已满
    {
        cout << "overflow!" << endl;
        return false;
    }
    else if(i<0 || i > V->VectorLength)  //插入位置错误
    {
        cout << "position error!" << endl;
        return false;
    }
    else
    {
        int j;
        for(j = V->VectorLength; j >= i; j--)  //后移
            V->elements[j+1] = V->elements[j];
        V->elements[i] = x;  //插入
        V->VectorLength++;   //向量长度+1
        return true;
    }
}

bool Remove(Vector *V,int i)  //删除向量的第i个表目
{
    if(V->VectorLength == 0)  //空向量
    {
        cout << "Vector is empty!" << endl;
        return false;
    }
    else if(i<0||i>V->VectorLength-1)  //删除位置错误
    {
        cout << "position error!" << endl;
        return false;
    }
    else {
        int j;
        for (j = 1; j < V->VectorLength - 1; j++)  //前移
            V->elements[j] = V->elements[j+1];
        V->VectorLength--;   //向量长度减1
        return true;
    }
}

Vector *Union(Vector *,Vector *)  //合并向量
{
    ElementType x;
//    Vector
}