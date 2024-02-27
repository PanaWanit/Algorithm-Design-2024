#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int dp[N][N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    string a,b;
    cin >> n >> m >> a >> b;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++)
            cin >> dp[i][j];
    }
    int ii = n, jj = m;
    string ans="";
    while(ii !=0 && jj!=0) {
        if(a[ii-1] == b[jj-1])
            ans += a[ii-1], ii--, jj--;
        else if(dp[ii-1][jj] > dp[ii][jj-1])
            ii--;
        else jj--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}