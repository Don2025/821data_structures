#include <bits/stdc++.h>
#define ms(a,x) memset(a,x,sizeof(a))
const int INF = 0x3f3f3f3f;
const int maxn = 101;
using namespace std;

int nexta[maxn];     //next数组 因为VSCode说next不明确所以写成nexta
int nextval[maxn];   //nudt的next数组

void get_next(string t) {
    ms(nexta,INF);
    int i = 1, j = 0;
    nexta[1] = 0;
    while(i < t.length()) {
        if(j==0 || t[i]==t[j]) {
            ++i; ++j;
            nexta[i] = j;
        }
        else j = nexta[j];
    }
    for(int k = 1; k < i; k++) {
        cout << (k==1?"   next:":" ") << setiosflags(ios::right) << setw(2) << nexta[k];
    }
    cout << endl;
}

void get_nextval(string t) { //nudt的next
    ms(nextval,INF);
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < t.length()) {
        if(j==0 || t[i]==t[j]) {
            ++i; ++j;
            nextval[i] = (t[i]==t[j])?nextval[j]:j;
        } else {
            j = nextval[j];
        }
    }
    for(int k = 1; k < i; k++) {
        cout << (k==1?"nextval:":" ") << setiosflags(ios::right) << setw(2) << nextval[k];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string t;
    cin >> t;
    t = ' '+t;  /*咳 这是因为天勤王道字符串和next数组下标都是从1开始的
    熊岳山下标是从0开始的且next[0]=-1; 如果输入的T串第一个字符为空格符,就把t=' '+t换掉,比如写成t='#'+t
    */
    for(int i = 1; i < t.length(); i++) {
        cout << (i==1?"      i:":" ") << setiosflags(ios::right) << setw(2) << i;
    }
    cout << endl;
    for(int i = 1; i < t.length(); i++) {
        cout << (i==1?"      T:":" ") << setiosflags(ios::right) << setw(2) << t[i];
    }
    cout << endl;
    get_next(t);
    get_nextval(t);
    return 0;
}