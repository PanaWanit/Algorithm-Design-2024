#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int in[N];
vector<int> adj[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0,u,v; i<n; i++) {
        cin >> u >> v;
        ++in[u], ++in[v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = n;
    queue<int> q;
    for(int i=0; i<n; i++)
        if(in[i] == 1) ans--, q.emplace(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto& x : adj[u]) {
            if(in[x] == 1) continue;
            if(--in[x] == 1)
                ans--, q.push(x);
        }
    }
    cout << ans << "\n";
    return 0;
}