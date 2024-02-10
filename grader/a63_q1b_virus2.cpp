#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 10;
int a[N];

int check(int l, int r) {
    if(r - l + 1 == 2) return 1;
    int mid = (l+r) / 2;
    int ans = check(l, mid) & check(mid+1, r);
    int cnt=0;
    for(int i=l; i<=mid; i++) cnt += a[i];
    for(int i=mid+1; i<=r; i++) cnt -= a[i];
    return (abs(cnt) <= 1) & ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q,n;
    cin >> q >> n;
    while(q--) {
        for(int i=0; i<1<<n; i++) cin >> a[i];
        cout << (check(0, (1<<n)-1)?"yes":"no") << "\n";
    }
    return 0;
}