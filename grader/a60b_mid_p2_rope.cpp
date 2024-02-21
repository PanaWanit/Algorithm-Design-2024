#include <bits/stdc++.h>
using namespace std;

const int N = 4001;
int c[3], dp[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, start=1e9;
    cin >> n;
    for(int i=0; i<3; i++)
        cin >> c[i], dp[c[i]] = 1, start = min(start, c[i]);
    for(int i=start+1; i<=n; i++) {
        for(auto& x : c) {
            if(i - x >= 0 && dp[i-x] ) dp[i] = max(dp[i], dp[i-x]+1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}