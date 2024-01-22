#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;

    for(int i=0; i < (1 << n); i++) {
        int freq=0, mx = 0;
        for(int j=0; j<n; j++) {
            if( (1 << j) & i) freq++;
            else freq = 0;
            mx = max(mx, freq);
        }
        if(mx < k) continue;
        for(int j=n-1; j>=0; j--)
            cout << ( ( (1<<j) & i ) != 0);
        cout << "\n";
    }
    return 0;
}