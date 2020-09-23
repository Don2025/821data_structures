#include <bits/stdc++.h>
using namespace std;
//算法1.1 计算修建游泳池工程造价 P8
typedef struct rectangle {
    double length,width;
}Rectangle;

Rectangle *InitRectangle(double l,double w) {  //初始化函数
    Rectangle  *temp = (Rectangle *)malloc(sizeof(Rectangle));
    temp->length = 1;
    temp->width = w;
    return temp;
}

double Area(Rectangle *r) { //计算矩形面积
    return r->length*r->width;
}

double Perimeter(Rectangle *r) { //计算矩形周长
    return 2*(r->length+r->width);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //定义俩个矩形
    double l,w;
    Rectangle *Pool, *PoolRim;
    double FenceCost, ConcreteCost, TotalCost;
    //输入游泳池的长和宽
    cout << "Enter the length of the pool:" << endl;
    cin >> l;
    cout << "Enter the width of the pool:" << endl;
    cin >> w;
    Pool = InitRectangle(l,w);
    PoolRim = InitRectangle(l+6,w+6);
    //计算栅栏造价
    FenceCost = Perimeter(PoolRim)*50;
    cout << endl << "Fencing Cost is " << FenceCost << endl;
    //计算过道造价
    ConcreteCost = (Area(PoolRim)-Area(Pool))*30;
    cout << "Concrete Cost is " << ConcreteCost << endl;
    //计算总造价
    TotalCost = FenceCost+ConcreteCost;
    cout << "Total cost is " << TotalCost << endl;
    return 0;
}