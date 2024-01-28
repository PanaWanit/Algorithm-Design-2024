#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1010;
int n;
ll a[N];

ll search(ll x) {
    ll l = 0, r = 1e18;
    while(l<r) {
        ll m = l + (r-l) / 2;
        ll sum = 0;
        for(int i=0; i<n; i++)
            sum += m / a[i] + 1;
        if(sum >= x) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    while(m--) { 
        ll x;
        cin >> x;
        cout << search(x) << "\n";
    }
    return 0;
}