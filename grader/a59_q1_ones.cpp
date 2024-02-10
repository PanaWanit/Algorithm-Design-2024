#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll s[16] = {0, 1};

ll dc(ll n, int k) {
    n = abs(n);
    if(n <= 11) {
        if(n <= 6) return n;
        return 13 - n;
    }

    ll qk = s[k];
    ll t = n / qk;

    return min(
        dc(n - t * qk, k-1) + t * k,
        dc(n - (t+1) * qk, k-1) + (t+1) * k
    );
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    for(int i=2; i<15; i++)
        s[i] = s[i-1] * 10 + 1;
    int start = upper_bound(s+1, s+15, n) - s;
    cout << dc(n, start) << "\n";
    return 0;
}