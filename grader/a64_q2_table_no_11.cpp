#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+1;
const int M = 1e8+7;

int dp[3][N]; // 0 [00], 1[01], 2[10]
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    for(int i=2; i<=n; i++) {
        dp[0][i] = ( (dp[0][i-1] + dp[1][i-1])%M + dp[2][i-1]) % M;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % M;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1]) % M;
    }
    cout << ( (dp[0][n] + dp[1][n]%M) + dp[2][n] )%M << "\n";
    return 0;
}