#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> v(n);
    vector<int> sum(n);
    for(auto& [s, c] : v) cin >> s >> c;
    sort(v.begin(), v.end());
    sum[0] = v[0].second;
    for(int i=1; i<n; i++) sum[i] = sum[i-1] + v[i].second;
    while(q--) {
        int i;
        cin >> i;
        int idx = lower_bound(sum.begin(), sum.end(), i) - sum.begin();
        cout << v[idx].first << "\n";
    }
    return 0;
}