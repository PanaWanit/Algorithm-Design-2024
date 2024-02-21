#include <bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[2][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, mx = -2e9;
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> dp[i&1][j];
            dp[i&1][j] += max(dp[i&1^1][j-1], dp[i&1^1][j]);
            mx = max(dp[i&1][j], mx);
        }
    }
    cout << mx << "\n";
    return 0;
}