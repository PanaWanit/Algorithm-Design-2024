#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N], ans[N];
struct ft {
    int a[N];
    void upd(int i, int v) {
        for(; i<N; i+=i&-i)
            a[i] += v;
    }
    int qry(int i) {
        int r = 0;
        for(; i; i-=i&-i)
            r += a[i];
        return r;
    }
} f;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        ans[a[i]] = f.qry(N-a[i]);
        f.upd(N-a[i]+1, 1);
    }
    while(m--) {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}