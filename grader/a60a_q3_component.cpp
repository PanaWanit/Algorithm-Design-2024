#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
vector<int> adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1;
    for(auto& x : adj[u]) {
        if(vis[x]) continue;
        dfs(x);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=0; i<n; i++) 
        if(!vis[i]) ans++, dfs(i);
    cout << ans << "\n";
    return 0;
}