#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int k;
int a[N];
void recur(int l, int r) {
    if(l+1==r) return;
    if(k <= 0) return;
    int m = (l+r) >> 1;
    k -= 2;
    swap(a[m], a[m-1]);
    recur(l, m);
    recur(m, r);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n >> k;
    iota(a, a+n, 1);
    k--;
    recur(0, n);
    if(k) 
        cout << "-1";
    else 
        for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}