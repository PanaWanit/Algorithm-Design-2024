#include <bits/stdc++.h>
using namespace std;

int find_mcs(vector<int>& v) {
    int mx = -2e9;
    int sum=0;
    for(auto& x : v) {
        sum += x;
        mx = max(mx, sum);
        sum = max(sum, 0);
    }
    return mx;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> vall(2*n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            vall[i-j+n].push_back(x);
        }
    }
    int mx = -2e9;
    for(auto& v : vall)
        mx = max(mx, find_mcs(v));
    cout << mx << "\n";
    return 0;
}