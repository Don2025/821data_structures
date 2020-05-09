#ifndef INC_821DATA_STRUCTURES_LINEARLIST_H
#define INC_821DATA_STRUCTURES_LINEARLIST_H

typedef int ElementType;
typedef struct LinearList   //线性表结构体
{
    ElementType *data;
    int MaxSize;
    int Last;
}LinearList;

void InitList(LinearList *,int sz);  //线性表的初始化
void FreeList(LinearList *);   //释放线性表的存储空间
bool ListEmpty(LinearList *);  //判断线性表是否为空
bool ListFull(LinearList *);  //判断线性表是否为满
int ListLength(LinearList *);  //求线性表的长度
ElementType GetElem(LinearList *,int i);  //取线性表的第i个表目
int LocateElem(LinearList *,ElementType x);  //在线性表中查找x结点
bool InsertElem(LinearList *,ElementType x,int i);  //在表中第i个位置插入值为x的结点
bool DeleteElem(LinearList *,int i);  //删除表中第i个结点
void printout(LinearList *);  //打印线性表的表目
void ListTestMain(void);

#endif //INC_821DATA_STRUCTURES_LINEARLIST_H
