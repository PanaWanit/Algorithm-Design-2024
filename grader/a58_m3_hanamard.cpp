#include <bits/stdc++.h>
using namespace std;

vector<int> v;

vector<int> dc(int l, int r) {
    if(l == r)
        return vector<int>{v[l]};
    int m = (l + r) >> 1;
    auto tl = dc(l, m), tr = dc(m+1, r);
    int n = tl.size();
    vector<int> ans(2 * n);
    for(int i=0; i <n; i++) {
        ans[i] = tl[i] + tr[i];
        ans[n+i] = tl[i] - tr[i];
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0, x; i<n; i++)
        cin >> x, v.push_back(x);

    auto ans = dc(0, n-1);
    for(auto& x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}