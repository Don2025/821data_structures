#ifndef INC_821DATA_STRUCTURES_WDSTRING_H
#define INC_821DATA_STRUCTURES_WDSTRING_H
#include <string>
using namespace std;

void get_next(string T,int next[]);
int index_kmp(string S,string T,int next[]);
void get_nextval(string T,int nextval[]);
void printArray(int arr[],int n);
void WDStringTextMain();

#endif //INC_821DATA_STRUCTURES_WDSTRING_H
