#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int dp[N][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,x;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> x;
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])+x;
            if(i>1 && j>1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2*x);
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}