#include <bits/stdc++.h>
using namespace std;

const int N = 33;
int dp[2][N][N][N]; // (last color), (#change), (consect), i
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,l;
    cin >> n >> m >> l;
    dp[0][0][1][1] = 1;
    for(int i=2; i<=n; i++) {
        for(int k=0; k<=min(i-1, l); k++) {
            for(int j=1; j<=min(i, m); j++) {
                if(k >= 1)
                    dp[0][k][1][i] += dp[1][k-1][j][i-1],
                    dp[1][k][1][i] += dp[0][k-1][j][i-1];

                dp[0][k][j][i] += dp[0][k][j-1][i-1];
                dp[1][k][j][i] += dp[1][k][j-1][i-1];
            }
        }
    }
    int sum = 0;
    for(int i=1; i<=m; i++)
        sum += dp[0][l][i][n] + dp[1][l][i][n];
    cout << sum << "\n";
    return 0;
}
