#include<bits/stdc++.h>
using namespace std;

const int N = 5001;
int a[N];
int dp[N][N];

int solve(int l, int r) {
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(r-l+1 == 2)
        return dp[l][r] = max(a[l], a[r]);

    return dp[l][r] = max({solve(l+2, r) + max(a[l], a[l+1]), 
                            solve(l, r-2) + max(a[r], a[r-1]),
                            solve(l+1, r-1) + max(a[l], a[r])
    });
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n) << "\n";
    return 0;
}