#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n;

int before[N];
int a[N], vis[N];

void permu(int state) {
    if(state == n) {
        for(int i=0; i<n; i++)
            cout << a[i]-1 << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++) {
        if(vis[i] || (before[i] != 0 && !vis[before[i]]) ) continue;
        vis[i] = 1;
        a[state] = i;
        permu(state+1);
        vis[i] = 0;
    }

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k;
    cin >> n >> k;
    while(k--) {
        int a,b;
        cin >> a >> b;
        before[b+1] = a+1;
    }
    permu(0);
    return 0;
}