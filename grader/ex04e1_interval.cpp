#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i].second;
    for(int i=0; i<n; i++)
        cin >> a[i].first;
    sort(a.begin(), a.end());
    int ans = 1, p = 0;
    for(int i=1; i<n; i++)
        if(a[i].second >= a[p].first) p = i, ans ++;
    cout << ans << "\n";
    return 0;
}