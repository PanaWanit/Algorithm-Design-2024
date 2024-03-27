#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int d[N];
vector<pair<int,int>> adj[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    memset(d, 0x3f, sizeof d);
    for(int i=0; i<n; i++) {
        for(int j=0, x; j<n; j++) {
            cin >> x;
            if(x <= 0) continue;
            adj[i].emplace_back(j, x);
        }
    }
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 0);
    d[0] = 0;
    while(!pq.empty()) {
        int u,w;
        tie(w, u) = pq.top();
        pq.pop();
        for(auto& [v, w] : adj[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.emplace(d[v], v);
            }
        }
    }
    int ans = *max_element(d, d+n);
    cout << (ans>1e9?-1:ans);
    return 0;
}