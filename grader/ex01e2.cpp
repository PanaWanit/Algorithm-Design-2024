#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100100;
ll a[N];

ll maxsub(int l, int r) {
    if(l==r) return a[l];
    int mid = (l+r)>>1;
    ll l_ans = maxsub(l, mid);
    ll r_ans = maxsub(mid+1, r);
    ll lmx=-1e18, rmx=-1e18, sum=0;
    for(int i=mid; i>=l; i--) {
        sum += a[i];
        lmx = max(lmx, sum);
    }
    sum = 0;
    for(int i=mid+1; i<=r; i++) {
        sum += a[i];
        rmx = max(rmx, sum);
    }
    ll mid_ans = lmx + rmx;
    return max({l_ans, r_ans, mid_ans});
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    cout << maxsub(1, n) << "\n";
    return 0;
}