#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    /*
        position of 'g'
        https://oeis.org/A120738
    */
    long long n;
    cin >> n;
    n--;
    long long l=0, r=1e9;
    while(l < r) {
        long long m = (l+r)/2;
        long long cur = 4*m - __builtin_popcountll(m);
        if(n == cur) {
            cout << "g\n";
            return 0;
        }
        if(n > cur) l = m + 1;
        else r = m;
    }
    cout << "a\n";
    return 0;
}