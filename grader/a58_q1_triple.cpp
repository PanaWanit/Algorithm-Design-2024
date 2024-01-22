#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
unordered_map<int, pair<int,int>> mp;
bool query() {
    int x;
    cin >> x;
    for(int i=0; i<n; i++) {
        if(!mp.count(x-v[i])) continue;
        auto key = mp[x-v[i]];
        if(key.first == i || key.second == i) continue;
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for(int i=0,x; i<n; i++) cin >> x, v.push_back(x);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            mp[v[i] + v[j]] = {i, j};
        }
    }

    while(m--)
        cout << (query()?"YES\n":"NO\n");
    return 0;
}