#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int a[N], l[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    int sum=0, ans=-2e9;
    memset(l, 0xc0, sizeof(l));
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
        l[i] = max(l[i-1], sum);
        sum = max(0, sum);
    }
    ans = l[n];
    sum = 0;
    int cur_max = -2e9;
    for(int i=n; i>=2; i--) {
        sum += a[i];
        cur_max = max(cur_max, sum);
        sum = max(0, sum);
        ans = max(ans, cur_max + l[i-1]);
    }
    cout << ans << "\n";
    return 0;
}