#include <bits/stdc++.h>
using namespace std;

vector<int> cum_size{1, 3};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    while(cum_size.back() <= (int)2e9) {
        int cur_size = lower_bound(cum_size.begin(), cum_size.end(), cum_size.size() + 1 /*next size*/) - cum_size.begin() + 1;
        cum_size.push_back(cum_size.back() + cur_size);
    }
    int q,i;
    for(cin >> q; q--;) {
        cin >> i;
        int ans = lower_bound(cum_size.begin(), cum_size.end(), i) - cum_size.begin() + 1;
        cout << ans << "\n";
    }
    return 0;
}