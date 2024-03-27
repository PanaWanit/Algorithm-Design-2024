#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
bool vis[N];

int dfs(int u, int p=-1) {
    vis[u] = 1;
    int ans=1;
    if(p==-1 && (int)adj[u].size() > 2) ans = 0;
    else if(p!=-1 && (int)adj[u].size() - 1 >= 2) ans=0;


    for(auto& x : adj[u]) {
        if(x == p) continue;
        if(vis[x]) {
            ans=0;
            continue;
        }
        ans &= dfs(x, u);
    }

    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        if(!vis[i]) ans += dfs(i);
    }
    cout << ans << "\n";
    return 0;
}