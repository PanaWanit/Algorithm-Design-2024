#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> dp[i];
        if(i==0) continue;
        int mx = -2e9;
        for(int j=1; j<=3; j++) {
            if(i - j >= 0) mx = max(mx, dp[i-j]);
        }
        dp[i] += mx;
    }
    cout << dp[n-1];
    return 0;
}