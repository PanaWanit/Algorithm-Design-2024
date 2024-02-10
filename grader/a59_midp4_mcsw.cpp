#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
deque<pair<int,int>> dq; 

// pref_sum[i] - min_j<i(pref_sum[j-1])
// i - j < w
// i - (j-1) < w + 1

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, w, sum=0, a, mx=-2e9;
    cin >> n >> w;
    dq.push_back({0, 0});
    for(int i=1; i<=n; i++) {
        cin >> a;
        sum += a;
        while(!dq.empty() && i - dq.front().second > w) dq.pop_front();
        while(!dq.empty() && dq.back().first >= sum) dq.pop_back();
        mx = max(mx, sum - dq.front().first);
        dq.push_back({sum, i});
    }
    cout << mx << "\n";
    return 0;
}