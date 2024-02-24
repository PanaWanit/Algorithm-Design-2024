#include <bits/stdc++.h>
using namespace std;

const int M = 1997;
const int N = 501;
int dp[N][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=min(i, k); j++) {
            dp[i][j] = (dp[i-1][j-1] + j * dp[i-1][j]%M)%M;
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}