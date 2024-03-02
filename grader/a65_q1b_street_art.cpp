#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<ll> v;

ll play(ll a, ll b, ll c) {
    ll cnt = upper_bound(all(v), c) - lower_bound(all(v), b);
    if(c - b + 1 < 3) return cnt;
    ll u = (c-b+1)/3;
    ll v = (c-b+2)/3;
    vector<ll> p{play(a+1, b, b+u-1), play(a+2, b+u, b+u+v-1), play(a+3, b+u+v, c)};
    sort(all(p));
    return cnt + p[1] + p[2];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll w; int n;
    cin >> w >> n;
    v.resize(n);
    for(auto& x : v) 
        cin >> x;
    sort(all(v));
    cout << play(0, 1, w) << "\n";
    return 0;
}