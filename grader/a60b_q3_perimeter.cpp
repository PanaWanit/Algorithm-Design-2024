#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<int> adj[N];
int d[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,e,k, cnt=0;
    cin >> n >> e >> k;
    memset(d, -1, sizeof d);
    while(e--) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    d[0] = 0;
    q.emplace(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(d[u] == k) {
            cnt ++ ;
            continue;
        }
        for(auto& x : adj[u]) {
            if(d[x] != -1) continue;
            d[x] = d[u] + 1 ;
            q.emplace(x);
        }
    }
    cout << cnt << "\n";
    return 0;
}