#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,q,m;
    cin >> n >> q >> m;
    for(int i=1; i<=n; i++) {
        cin >> dp[i];
        dp[i] += dp[i-1] - m;
    }
    while(q--) {
        int p, w;
        cin >> p >> w;
        int sz = lower_bound(dp+p, dp+n+1, dp[p-1] + w) - dp;
        cout << sz << "\n";
    }
    return 0;
}