#include "WDString.h"
#include <iostream>
using namespace std;

void get_next(string T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length())
    {
        if(j==0 || T[i]==T[j])
        {
            ++i; ++j;
            next[i] = j;
        }
        else j = next[j];
    }
    printf("The next array is:");
    printArray(next,T.length());
}

int index_kmp(string S,string T,int next[])
{
    int i = 1, j = 1;
    while(i<=S.length() && j <=T.length())
    {
        if(j==0||S[i]==T[i])
        {
            ++i; ++j;
        }
        else j = next[j];
    }
    return (j>T.length()? i-T.length():0);
}

void get_nextval(string T,int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i<T.length())
    {
        if(j==0||T[i]==T[j])
        {
            ++i; ++j;
            if(T[i]!=T[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        }
        else j = nextval[j];
    }
    printf("The nextval array is:");
    printArray(nextval,T.length());
}

void printArray(int arr[],int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%s%d",i==1?"":" ",arr[i]);
    }
    printf("\n");
}

void WDStringTextMain()
{
    const int maxn = 61;
    string s,t;
    cout << "Please input s t:" << endl;
//    cin >> s >> t;
    s = "aaabaaaaab",t = "aaaab";
    int next[maxn],nextval[maxn];
    for(int i = 0; i < s.length(); i++)
    {
        cout << (i==0?"":" ") << s[i];
    }
    cout << endl;
    get_next(t,next);
    get_nextval(t,nextval);
    cout << "index_kmp is:" << index_kmp(s,t,next) << endl;
}
