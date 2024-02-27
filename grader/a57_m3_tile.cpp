#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int dp[11][N+10];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i=1, x; i<=n; i++) {
        cin >> x;
        for(int j=1; j<=100; j++) {
            for(int k=1; k<=m; k++)
                if(k-j*j >= 0 && dp[i-1][k-j*j] != -1) {
                   dp[i][k] = min( dp[i][k]==-1 ? INT_MAX : dp[i][k], dp[i-1][k-j*j] + (j-x)*(j-x));

                }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}