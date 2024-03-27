#include <bits/stdc++.h>
using namespace std;

const int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
struct A {
    int i,j,w;
    bool operator < (const A& o) const {
        return w > o.w;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m, 1e9));
    for(auto& x : a)
        for(auto& y : x)
            cin >> y;
    
    d[0][0] = 0;
    priority_queue<A> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        int ni = pq.top().i, nj = pq.top().j, w = pq.top().w;
        pq.pop();
        for(int i=0; i<4; i++) {
            int ii = ni + di[i], jj = nj + dj[i];
            if(ii >= n || jj >= m || ii < 0 || jj <0) continue;
            if(d[ii][jj] > w + a[ii][jj]) {
                d[ii][jj] = w + a[ii][jj];
                pq.push({ii, jj, d[ii][jj]});
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}