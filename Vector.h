#ifndef INC_821DATA_STRUCTURES_VECTOR_H
#define INC_821DATA_STRUCTURES_VECTOR_H

typedef int ElementType;
typedef struct Vector  //向量结构体
{
    ElementType *elements;
    int ArraySize;
    int VectorLength;
}Vector;

void GetArray(Vector *);  //申请向量的存储空间
void InitVector(Vector *,int sz);  //初始化一空向量
ElementType GetNode(Vector *,int i);  //取向量的第i个表目
void FreeVector(Vector *);  //释放向量的存储空间
int Find(Vector *,ElementType x);  //在向量中查找
bool Insert(Vector *,ElementType x,int i);  //在向量的第i个位置插入值为x的新结点
bool Remove(Vector *,int i);  //删除向量的第i个表目
Vector *Union(Vector *,Vector *);  //向量并集
Vector *Instersection(Vector *,Vector *);  //向量交集

#endif //INC_821DATA_STRUCTURES_VECTOR_H
