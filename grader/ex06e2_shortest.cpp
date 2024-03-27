#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,s;
    cin >> n >> m >> s;
    vector<tuple<int,int,int>> e;
    while(m--) {
        int u,v,w;
        cin >> u >> v >> w;
        e.emplace_back(u, v, w);
    }
    vector<int> d(n, 1e9);
    d[s] = 0;

    for(int i=0; i<n-1; i++) {
        for(auto& [u, v, w] : e)
            d[v] = min(d[v], d[u] + w);
    }
    vector<int> tmp(d);
    for(auto& [u, v, w] : e)
        d[v] = min(d[v], d[u] + w);

    if(d != tmp)
        cout << -1;
    else
        for(auto& x : d) cout << x << " ";
    cout << "\n";
    return 0;
}