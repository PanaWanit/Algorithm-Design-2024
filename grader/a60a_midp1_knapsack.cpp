#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int dp[N][N];
int v[N], w[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> v[i];
    for(int i=1; i<=n; i++) cin >> w[i];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) 
            cin >> dp[i][j];
    }
    int i = n, j = m;
    vector<int> ans;
    while(i != 0 && j != 0) {
        int jj = j;
        if(j-w[i] >= 0 && dp[i-1][j-w[i]]+v[i] > dp[i-1][j])
            jj = j-w[i], ans.push_back(i);
        i--, j = jj;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto& x : ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}