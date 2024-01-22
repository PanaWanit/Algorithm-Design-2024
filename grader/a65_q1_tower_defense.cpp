#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<int> idx(m), pos(m), heal(m), tower(k);
    iota(idx.begin(), idx.end(), 0);
    for(auto& x : pos) cin >> x;
    for(auto& x : heal) cin >> x;
    for(auto& x : tower) cin >> x;

    sort(idx.begin(), idx.end(), [&](const int& ia, const int& ib) {
        return pos[ia] < pos[ib];
    });
    sort(tower.begin(), tower.end());

    int cur_mon = 0;
    for(auto& cur_tower : tower) {
        int i = idx[cur_mon];
        while(cur_mon < m && cur_tower - pos[i] > w) i = idx[++cur_mon];
        if(cur_mon < m && abs(pos[i] - cur_tower) <= w) {
          heal[i] -= 1;
          if(heal[i] == 0) cur_mon++;
        }
        if(cur_mon == m) break;
    }

    cout << accumulate(heal.begin(), heal.end(), 0) << "\n";
    return 0;
}