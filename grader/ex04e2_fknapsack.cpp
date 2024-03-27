#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

pair<double, double> a[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    double w;
    cin >> w >> n;
    for(int i=0; i<n; i++)
        cin >> a[i].first;
    for(int i=0; i<n; i++)
        cin >> a[i].second;

    sort(a, a+n, [](const auto& a, const auto& b) {
        return a.first * b.second > b.first * a.second; // floating evil point
    });

    double ans = 0;
    for(int i=0; i<n; i++) {
        if(w > a[i].second) ans += a[i].first, w -= a[i].second;
        else {
            ans += a[i].first * w / a[i].second;
            break;
        }
    }

    cout << fixed << setprecision(4) << ans;
    return 0;
}