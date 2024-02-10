#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A, B;
const int N = 1e5+10;
int k;
ll a[N];

ll solve(ll l, ll r) {
    ll size = upper_bound(a, a+k, r) - lower_bound(a, a+k, l);
    if(size == 0) return A;
    ll ans = B * size * (r-l+1);
    if(l==r) return ans;
    ll mid = l + (r-l)/2;
    return min(ans, solve(l, mid) + solve(mid+1, r));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n >> k >> A >> B;
    n = 1ll << n;
    for(int i=0; i<k; i++)
        cin >> a[i];
    sort(a, a+k);
    cout << solve(1, n);
    return 0;
}