#include <bits/stdc++.h>
using namespace std;

int msb(int x) {
    return 1 << (31 - __builtin_clz(x));
}
int dc(int n, int l, int r, int sz, int fst=1) {
    if(n <= 1) 
        return n;
    int sum = (l <= fst+sz && fst+sz <= r && n%2 );
    if(l < fst + sz) sum += dc(n >> 1, l, r, sz >> 1, fst);
    if(r > fst + sz) sum += dc(n >> 1, l, r, sz >> 1, fst + sz + 1);

    return sum;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,l,r;
    cin >> n >> l >> r;
    cout << dc(n, l, r, msb(n)-1) << "\n";
    return 0;
}