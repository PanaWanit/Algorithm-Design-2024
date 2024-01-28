#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int cnt[N], deg[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, k=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0,x; j<n; j++) {
            cin >> x;
            if(i < j && x) {
                deg[i]++, deg[j]++;
                k = max({k, deg[i], deg[j]});
            }
        }
    }
    for(int i=0; i<n; i++) cnt[deg[i]]++;
    for(int i=0; i<=k; i++) cout << cnt[i] << " ";
    return 0;
}