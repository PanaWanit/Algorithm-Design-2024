#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    while(m--) {
        int x;
        cin >> x;
        int i = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
        if(i < 0) cout << -1 << "\n";
        else cout << v[i] << "\n";
    }
    return 0;
}