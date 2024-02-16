#include<bits/stdc++.h>
using namespace std;

int n, mn, m;
int a[1002];
vector<int> v[1001];
void play(int st, int last, int cnt=0) {
    if(cnt == n) {
        mn = min(mn, st);
    }
    if(st >= mn || cnt == n) {
        return;
    }
    for(int i=last; i<m; i++) {
        for(auto& x : v[i]) {
            if(!a[x]) cnt++;
            a[x] ++;
        }
        play(st+1, i+1, cnt);
        for(auto& x : v[i]) {
            a[x] --;
            if(!a[x]) cnt--;
        }

    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x; cin >> x;
        while(x--) {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }
    mn = m;
    play(0, 0);
    cout << mn << "\n";
    return 0;
}