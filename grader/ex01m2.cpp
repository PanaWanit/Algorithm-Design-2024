#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N], b[N], sum=0;
void merge_sort(int l, int r) {
    if(l==r) return;
    int m = (l+r)>>1;
    merge_sort(l, m), merge_sort(m+1, r);
    int pl = l, pr = m+1, pall=l;
    while(pl <= m && pr <= r) {
        if(a[pl] <= a[pr]) b[pall++] = a[pl++];
        else b[pall++] = a[pr++], sum += m - pl + 1;
    }
    while(pl <= m) b[pall++] = a[pl++];
    while(pr <= r) b[pall++] = a[pr++];
    for(int i=l; i<=r; i++) a[i] = b[i];
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    merge_sort(0, n-1);
    cout << sum << "\n";
    return 0;
}
/*
[1 3 10 20] [2 5 6]
*/