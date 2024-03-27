#include <bits/stdc++.h>
using namespace std;

const int N = 5000+10;

int d[N];

struct A {
    int v,w;
    A(int v, int w): v(v), w(w){}
    bool operator < (const A& o) const {
        return w > o.w;
    }
};
vector<A> adj[N];
priority_queue<A> pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,k,e;
    cin >> n >> m >> k >> e;
    memset(d, 0x3f, sizeof d);
    while(k--) {
        int u;
        cin >> u;
        d[u] = 0;
        pq.emplace(u, 0);
    }
    while(m--) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    while(!pq.empty()) {
        int u=pq.top().v, w = pq.top().w;
        pq.pop();
        for(auto& x : adj[u]) {
            if(d[x.v] > w + x.w) {
                d[x.v] = w + x.w;
                pq.emplace(x.v, d[x.v]);
            }
        }
    }

    cout << d[e] << "\n";
    return 0;
}