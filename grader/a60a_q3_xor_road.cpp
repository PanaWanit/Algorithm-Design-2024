#include <bits/stdc++.h>
using namespace std;

const int N = 2002;

int a[N];
struct dsu {
    int n, p[N];
    dsu(int n): n(n) {
        iota(p, p+n, 0);
    }
    int fr(int i) {
        return (p[i]^i)? p[i]=fr(p[i]): i;
    }
    bool join(int u, int v) {
        int ru = fr(u), rv = fr(v);
        if(ru == rv) return false;
        p[ru] = rv;
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    dsu p(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<tuple<int,int,int>> e;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++)
            e.emplace_back(-(a[i] ^ a[j]), i, j);
    }
    sort(e.begin(), e.end());
    long long ans = 0;
    for(auto& [w, i, j] : e) {
        if(p.join(i, j))
            ans -= w;
    }
    cout << ans << "\n";
    return 0;
}