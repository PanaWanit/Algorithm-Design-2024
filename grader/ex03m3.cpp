#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int dp[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    k = min(n-1, k);
    deque<int> dq;
    for(int i=1, x; i<=n; i++) {
        cin >> x;
        while(!dq.empty() && i-dq.front() > 2*k+1) dq.pop_front();
        if(i <= k+1) dp[i] = x;
        else dp[i] = dp[dq.front()]+x;
        while(!dq.empty() && dp[i] <= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    cout << *min_element(dp+n-k, dp+n+1) << "\n";
    return 0;
}