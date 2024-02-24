#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][N], a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    ++n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int sz=3; sz<=n; sz++) {
        for(int l = 1; l + sz - 1 <= n; l++) {
            int r = l + sz - 1;
            dp[l][r] = 2e9;
            for(int m = l+1; m < r; m++) {
                int cost = dp[l][m] + dp[m][r] + a[l]*a[m]*a[r];
                dp[l][r] = min(dp[l][r], cost);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}