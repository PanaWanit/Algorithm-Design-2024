#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 8;
int a[N];
int n;

bool dc(int l, int r) {
    if(r - l + 1 == 2) return !a[l] && a[r];
    
    int mid = (l+r)/2;

    bool a_ans = dc(l, mid);
    reverse(a+l, a+mid+1);
    a_ans |= dc(l, mid);
    reverse(a+l, a+mid+1); // back tracking
    
    bool b_ans = dc(mid+1, r);

    return a_ans & b_ans;

}

void solve() {
    for(int i=0; i<n; i++)
        cin >> a[i];
    cout << (dc(0, n-1)?"yes":"no") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int q;
    cin >> q >> n;
    n = 1 << n;
    while(q--) {
        solve();
    }
    return 0;
}