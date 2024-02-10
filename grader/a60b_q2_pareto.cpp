#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(auto& [f,s] : v) cin >> f >> s;
    sort(v.begin(), v.end());
    int ans=1, cur = v.back().second;
    for(int i=v.size()-2; i>=0; i--) {
        if(v[i].second > cur)
            cur = v[i].second, ans++;
    }
    cout << ans << "\n";
    return 0;
}