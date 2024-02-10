#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5+10;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m; ll k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i], a[i] += a[i-1];
    while(m--) {
        int start; ll cost;
        cin >> start >> cost;
        ++start;
        int l = start-1, r = n;
        while(l < r) {
            int m = (l + r + 1) >> 1;
            if(a[m] - a[start - 1] + (m - start + 1) * k <= cost)
                l = m;
            else r = m-1;
        }
        cout << a[l] - a[start-1] << "\n";
    }
    return 0;
}