#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[2][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int mx = 0;
    int n, m;
    cin >> n >> m;
    string s;
    for(int i=1; i<=n; i++) {
        cin >> s;
        for(int j=1; j<=m; j++) {
            if(s[j-1] == '0') {
                dp[i&1][j] = 0;
                continue;
            }
            dp[i&1][j] = min({dp[i&1^1][j-1], dp[i&1][j-1], dp[i&1^1][j]})+1;
            mx = max(mx, dp[i&1][j]);
        }
    }
    cout << mx << "\n";
    return 0;
}