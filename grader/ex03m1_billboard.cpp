#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int dp[2][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1,x; i<=n; i++) {
        cin >> x;
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = dp[0][i-1] + x;
    }
    cout << max(dp[0][n], dp[1][n]);
    return 0;
}