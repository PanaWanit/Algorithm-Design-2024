#include <bits/stdc++.h>
using namespace std;


bool similar(string a, string b, int n) {
    if(a == b) return true;
    if(n==0) return false;
    int sz = n/2;
    string a1 = a.substr(0, sz), a2 = a.substr(sz);
    string b1 = b.substr(0, sz), b2 = b.substr(sz);
    if(similar(a1, b1, n/2) && similar(a2, b2, n/2)) return true;
    if(similar(a1, b2, n/2) && similar(a2, b1, n/2)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << (similar(a, b, a.size()) ? "YES":"NO");
    return 0;
}