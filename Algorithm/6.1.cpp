#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int key;
}T;

int seqSearch(T A[], int key, int n) {//À≥–Ú≤È’“
    for(int i = 0; i < n; i++) {
        if(A[i].key==key) {
            cout << "seq: key" << key << "is found, subscript is " << i << endl;
            return i;
        }
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    return 0;
}