#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[2*N];

deque<pair<int,int>> dq;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[n+i] = a[i];
    }

    // from a59_midp4_mcsw
    int sum=0, mx = -2e9;
    int w = n;
    dq.push_back({0, 0});
    for(int i=1; i<=2*n; i++) {
        sum += a[i];
        while(!dq.empty() && i - dq.front().second > w) dq.pop_front();
        while(!dq.empty() && dq.back().first >= sum) dq.pop_back();
        mx = max(mx, sum - dq.front().first);
        dq.push_back({sum, i});
    }
    cout << mx << "\n";
    return 0;
}