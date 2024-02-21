#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int qs[N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> qs[i][j];
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }
    while(q--) {
        int si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;
        si++, sj++, ei++, ej++;
        cout << qs[ei][ej] - qs[ei][sj-1] - qs[si-1][ej] + qs[si-1][sj-1] << "\n";
    }
    return 0;
}