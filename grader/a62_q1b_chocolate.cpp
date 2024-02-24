#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+3;
const int N = 1e4+1;

int dp[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> v(k);
    for(auto& x : v) cin >> x;
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(auto& x : v) {
            if(i >= x) dp[i] = (dp[i] + dp[i-x])%M;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}