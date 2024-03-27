#include <bits/stdc++.h>
using namespace std;

const int N = 110;

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
char a[N][N];
int d[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> (a[i] + 1);
    }
    queue<pair<int,int>> q;
    memset(d, -1, sizeof d);
    d[1][1] = 0;
    q.push({1, 1});
    while(!q.empty()) {
        int ni,nj;
        tie(ni, nj) = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii > n || jj > m || ii < 1 || jj < 1) continue;
            if(a[ii][jj] == '#' || d[ii][jj] != -1) continue;
            d[ii][jj] = d[ni][nj] + 1;
            q.push({ii, jj});
        }
    }


    cout << d[n][m] << "\n";
    return 0;
}