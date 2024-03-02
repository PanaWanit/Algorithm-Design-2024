#include <bits/stdc++.h>
using namespace std;

const int N = 501;
int a[N], dp[N][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i>1) dp[i-1][i] = max(a[i]*a[i-1], 0);
    }
    for(int sz=3; sz<=n; sz++) {
        for(int l=1; l+sz-1<=n; l++) {
            int r = l + sz - 1;
            for(int m=l; m<r; m++) {
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m+1][r]);
            }
            dp[l][r] = max(dp[l][r], dp[l+1][r-1]+a[l]*a[r]);
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}