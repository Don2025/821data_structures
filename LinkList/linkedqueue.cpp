#include "node.h"
#include "linkedlist.h"
#include "linkedqueque.h"
using namespace std;

void InitLinkedQueue(LinkedQueue *LQ) {  //初始化链式队列
    LQ->queue = (LinkedList *)malloc(sizeof(LinkedList));
    InitLinkedList(LQ->queue);
}

void InQueue(LinkedQueue *LQ, ElementType item) { //入队
    SetPosition(LQ->queue,item);   //设置队尾元素为当前结点
    InsertAfter(LQ->queue,item);   //在队尾结点后插入结点
}

ElementType OutQueue(LinkedQueue *LQ) {  //出队
    ElementType tmpData;
    if(!(LQ->queue)->size) {
        cout << "OutQueue: underflowed!" << endl;
        exit(1);
    }
    SetPosition(LQ->queue,0);  //当前结点位置移动到队列头
    tmpData = GetData(LQ->queue);  //保存队首结点的数据
    DeleteAt(LQ->queue);    //删除队首结点
    return tmpData;   //返回被删除的队首元素
}
ElementType GetFront(LinkedQueue *LQ) {  //读取队首元素
    if(!(LQ->queue)->size) {
        cout << "Front: underflowed" << endl;
        exit(1);
    }
    return GetData(LQ->queue);
}

void ClearLQ(LinkedQueue *LQ) { //清除队列中的数据元素
    Clear(LQ->queue);
}
bool isEmptyLQ(LinkedQueue *LQ) {    //判断链队是否为空
    return (LQ->queue)->size?false:true;
}