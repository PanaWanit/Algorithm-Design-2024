#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

int dp[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    while(n--) {
        int x;
        cin >> x;
        for(int i=x; i<=m; i++) {
            dp[i] = min(dp[i], dp[i-x]+1);
        }
    }
    cout << dp[m] << "\n";
    return 0;
}