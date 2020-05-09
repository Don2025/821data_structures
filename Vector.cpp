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

Vector *Union(Vector *Va,Vector *Vb)  //向量并集
{   //把向量Va,Vb合并到Vc中，重复元素只保留一个
    int m,n,i,j,k;
    ElementType x;
    Vector *Vc = (Vector *)malloc(sizeof(Vector));
    n = Va->VectorLength;
    m = Vb->VectorLength;
    InitVector(Vc,m+n);
    j = 0;
    for(i = 0; i < n; i++)
    {
        x = GetNode(Va,i);  //从Va中取一结点
        Insert(Vc,x,j);
        j++;
    }
    for(i = 0; i < m; i++)
    {
        x = GetNode(Vb,i);  //从Vb中取一结点
        k = Find(Va,x);  //在Va中查找等值结点
        if(k == -1)  //若找不到同值站点则插到Vc的最后面
        {
            Insert(Vc,x,j);
            j++;
        }
    }
    return Vc;
}

Vector *Intersection(Vector *Va,Vector *Vb)  //向量交集
{  //求Va和Vb中的相同元素，并存入Vc
    int m,n,i,j,k;
    ElementType x;
    Vector *Vc = (Vector *)malloc(sizeof(Vector));
    n = Va->VectorLength;
    m = Vb->VectorLength;
    InitVector(Vc,(m>n)?n:m);  //取较小的向量大小作为向量交集的初始化大小
    i = 0;
    j = 0;
    while(i<m)
    {
        x = GetNode(Vb,i);  //从Vb中取一结点
        k = Find(Va,x);  //在Va中查找等值结点
        if(k != -1)  //若找到等值结点
        {
            Insert(Vc, x, j);
            i++;
        }
    }
    return Vc;
}

void printOut(Vector *V)  //打印向量
{
    int i;
    for(i = 0; i < V->VectorLength; i++)
        cout << (i==0?"":" ") << V->elements[i];
    cout << endl;
}

void VectorTestMain()
{
    Vector *V = (Vector *)malloc(sizeof(Vector));
    InitVector(V,10);
    for(int i = 10; i <= 50; i+=10)
        Insert(V,i,0);
    cout << "After initVector:";
    printOut(V);
    cout << "The node(pos 3) is:" << GetNode(V,3) << endl;
    cout << "The position of node 30 is:" << Find(V,30) << endl;
    Remove(V,2);
    cout << "After removing the node(pos:2),the Vector is:";
    printOut(V);
    Vector *tmp = (Vector *)malloc(sizeof(Vector));
    InitVector(tmp,5);
    for(int i = 10; i <= 60; i+=20)
        Insert(tmp,i,0);
    cout << "VectorA is:";
    printOut(V);
    cout << "VectorB is:";
    printOut(tmp);
    cout << "The Union of VectorA and VectorB is:";
    printOut(Union(V,tmp));
    cout << "The Intersection of VectorA and VectorB is:";
    printOut(Intersection(V,tmp));
    FreeVector(V);
    FreeVector(tmp);
}