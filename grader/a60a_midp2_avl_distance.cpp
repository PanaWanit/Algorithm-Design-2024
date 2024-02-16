#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+10, K = 20;
vector<int> adj[N];
int dp[2][K][N]; // [left, right][dist][node]

void dfs(int u) {
    if(adj[u].empty()) return;
    for(int i=0; i<(int)adj[u].size(); i++) {
        int x = adj[u][i];
        dfs(x);
        dp[i][1][u] = 1;
        for(int j=2; j<K; j++)
            dp[i][j][u] = dp[0][j-1][x] + dp[1][j-1][x];
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i=n-1; i--;) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);

    int ans=0;
    for(int i=1; i<=n; i++) {
        if(k < K)
            ans += dp[0][k][i] + dp[1][k][i];
        if((int)adj[i].size() == 2) {
            for(int j=1; j<k; j++) {
                if(k - j >= K || j >= K) continue;
                ans += dp[0][k-j][i] * dp[1][j][i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}