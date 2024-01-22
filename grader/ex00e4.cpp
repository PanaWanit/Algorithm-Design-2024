#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int r,n;
    cin >> r >> n;
    for(int i=0; i< (1<<n); i++) {
        if(__builtin_popcount(i) != r) continue;
        for(int j=n-1; j>=0; j--)
            cout << ( ( (1<<j) & i ) != 0);
        cout << "\n";
    }
    return 0;
}