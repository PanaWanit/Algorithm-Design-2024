#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
const int K = 51;

int n,w,k;
int _dp[K][2][2][N]; // k, choose, (0-left, 1-right), i
int l[N], r[N];

void solve_non_bonus() {
    auto dp = _dp[0];
    for(int i=1; i<=n; i++) {
        dp[0][0][i] = max(dp[0][0][i-1], dp[1][0][i-1]);
        dp[0][1][i] = max(dp[0][1][i-1], dp[1][1][i-1]);

        dp[1][0][i] = dp[0][1][max(i-w, 0)] + l[i];
        dp[1][1][i] = dp[0][0][max(i-w, 0)] + r[i];
    }
    cout << max({dp[0][0][n], dp[0][1][n], dp[1][0][n], dp[1][1][n]}) << "\n";
}
void solve_bonus() {
    auto dp = _dp;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=min(i, k); j++) {
            dp[j][0][0][i] = max(dp[j][0][0][i-1], dp[j][1][0][i-1]);
            dp[j][0][1][i] = max(dp[j][0][1][i-1], dp[j][1][1][i-1]);

            dp[j][1][0][i] = dp[j-1][0][1][max(i-w, 0)] + l[i];
            dp[j][1][1][i] = dp[j-1][0][0][max(i-w, 0)] + r[i];
        }
    }

    int mx = 0;
    for(int i=0; i<=k; i++)
        mx = max({dp[i][0][0][n], dp[i][0][1][n], dp[i][1][0][n], dp[i][1][1][n]});
    cout << mx << "\n";
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> w >> k;
    for(int i=1; i<=n; i++) cin >> l[i];
    for(int i=1; i<=n; i++) cin >> r[i];
    if(k == n) solve_non_bonus();
    else solve_bonus();
    return 0;
}