#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Matrix = array<array<ll, 2>, 2>;
ll mod;

Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix tmp;
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            tmp[i][j] = 0;
            for(int k=0; k<2; k++)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
        }
    }
    return tmp;
}

ostream &operator <<(ostream& o, const Matrix& a) {
    for(int i=0; i<4; i++)
        o << a[i/2][i%2] << " ";
    return o;
}

Matrix mop(Matrix a, int n) {
    Matrix ans = {1, 0, 0, 1};
    for(; n; n >>= 1, a = a * a) {
        if(n & 1) ans = ans * a;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n >> mod;
    Matrix start;
    cin >> start[0][0] >> start[0][1] >> start[1][0] >> start[1][1];
    cout << mop(start, n);
    return 0;
}