#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5+10;
ll qs[N], a[N];
vector<int> v[2002];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    ll ans = -1e18;
    for(int i=1; i<=n; i++) {
        cin >> qs[i]; 
        a[i] = qs[i];
        ans = max(ans, a[i]);
        qs[i] += qs[i-1];
        v[a[i] + 1000].push_back(i); 
    }
    
    for(int i=1; i<=1999; i++) {
        if((int)v[i].size() <= 1) continue;
        vector<int> cur;
        ll number = i - 1000;
        ll mx = -1e18, sum=number;

        for(int j=1; j<(int)v[i].size(); j++) {
            int  now = qs[ v[i][j] ] - qs [ v[i][j-1] ];

            sum += now;
            mx = max(mx, sum);
            sum = max(sum, number);
        }
        ans = max(ans, mx);
    }
    cout << ans << "\n";
    return 0;
}