#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    dp[1][0] = 1, dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i][0] = 1;
        for(int j=1; j<=k; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
    }
    cout << dp[n][k] << "\n";
    return 0;
}