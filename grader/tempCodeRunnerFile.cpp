#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int k;
int a[N];
void recur(int l, int r) {
    int m = (l+r) >> 1;
    if(k <= 0) return;
    k -= 2;
    swap(a[m], a[m+1]);
    recur(l, m);
    recur(m+1, r);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n >> k;
    iota(a, a+n, 1);
    k--;
    recur(0, n-1);
    if(k) 
        cout << "-1";
    else 
        for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}

/*
4
1 2 3 4 5 6 : 1
1 2 4 3 5 6 : 3
1 4 2 3 5 6 : 5
*/