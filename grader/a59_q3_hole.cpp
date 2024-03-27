#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
int d[N+1][N+1], a[N+1][N+1];
int e[N+1][N+1];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,si,sj;
    cin >> n >> si >> sj;
    while(n--) {
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    memset(e, 0x3f, sizeof(e));
    priority_queue< tuple<int,int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    for(int i=1; i<=N; i++) {
        e[1][i] = a[1][i], e[i][1] = a[i][1], e[N][i] = a[N][i], e[i][N] = a[N][i];
        pq.emplace(e[1][i], 1, i), pq.emplace(e[i][1], i, 1), pq.emplace(e[N][i], N, i), pq.emplace(e[i][N], i, N);
    }

    while(!pq.empty()) {
        int w, ni, nj;
        tie(w, ni, nj) = pq.top();
        pq.pop();
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii < 1 || jj < 1 || ii > N || jj > N) continue;
            if(w + a[ii][jj] >= e[ii][jj]) continue;
            e[ii][jj] = w + a[ii][jj];
            pq.emplace(e[ii][jj], ii, jj);
        }
    }

    queue<pair<int,int>> q;
    memset(d, -1, sizeof d);
    d[si][sj] = 0;
    q.emplace(si, sj);
    int mn = 2e9;

    while(!q.empty()) {
        int ni, nj;
        tie(ni, nj) = q.front();
        q.pop();
        mn = min(e[ni][nj], mn);
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii < 1 || jj < 1 || ii > N || jj > N) continue;
            if(a[ii][jj] || d[ii][jj] != -1) continue;
            d[ii][jj] = 0;
            q.emplace(ii, jj);
        }
    }    
    cout << mn << "\n";

    return 0;
}