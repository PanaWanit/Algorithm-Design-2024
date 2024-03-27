#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<int> adj[N];
bool vis[N];
bool dfs(int u, int p=-1) {
    if(vis[u]) return true;
    vis[u] = 1;
    bool ans = false;
    for(auto& x : adj[u]) {
        if(x == p) continue;
        ans |= dfs(x, u);
    }
    return ans;
}
void solve() {
    int n,e;
    cin >> n >> e;

    while(e--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = false;
    for(int i=0; i<n; i++)
        if(!vis[i]) ans |= dfs(i);

    cout << (ans?"YES":"NO") << "\n";

    memset(vis, 0, sizeof vis);
    for(int i=0; i<n; i++)
        adj[i].clear();
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    for(cin>>q; q--;)
        solve();
    return 0;
}