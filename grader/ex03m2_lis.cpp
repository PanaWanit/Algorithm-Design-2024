#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, x;
    cin >> n;
    vector<int> lis;
    while(n--) {
        cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    cout << lis.size() << "\n";
    return 0;
}