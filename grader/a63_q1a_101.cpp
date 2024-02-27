#include <bits/stdc++.h>
using namespace std;

const int M = 1e8+7;
const int MAT_SZ = 3;
using mat = array<array<int, MAT_SZ>, MAT_SZ>;
using vec = array<int, MAT_SZ>;

mat operator*(const mat& a, const mat& b) {
    mat ans = {};
    for(int i=0; i<MAT_SZ; i++) {
        for(int j=0; j<MAT_SZ; j++) {
            int cur = 0;
            for(int k=0; k<MAT_SZ; k++)
                cur = ( cur + 1ll*a[i][k]*b[k][j]% M ) % M;
            ans[i][j] = (int)cur;
        }
    }
    return ans;
}
mat& operator*=(mat& a, const mat& b) {
    return a = a*b;
}

vec dot(const mat& a, const vec& v) {
    vec ans;
    for(int i=0; i<MAT_SZ; i++) {
        ans[i] = 0;
        for(int j=0; j<MAT_SZ; j++)
            ans[i] = (ans[i] + 1ll*a[i][j]*v[j]%M ) % M;
    }
    return ans;
}


mat dp[40];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    long long n;
    cin >> n, n-=3;
    dp[0] = {
        1, 0, 1,
        1, 0, 0,
        0, 1, 1
    };
    for(int i=1; i<40; i++)
        dp[i] = dp[i-1] * dp[i-1]; // compute mat 2^n

    mat transform = {};
    for(int i=0; i<MAT_SZ; i++) transform[i][i] = 1;

    for(int i=0; i<40; i++)
        if((1ll<<i)&n) transform *= dp[i];
    
    const vec start = { 1, 1, 1 };
    vec ans = dot(transform, start);
    cout << (ans[0]*2%M + ans[1]*2%M + ans[2]*3%M)%M << "\n";
    return 0;
}
/*
    [0-6] = [000, 001, 010, 011, 100, 110, 111]

    dp[0] = dp[0] + dp[4] 
    dp[1] = dp[0] + dp[4]
    dp[2] = dp[1]
    dp[3] = dp[1]
    dp[4] = dp[2] + dp[5]
    dp[5] = dp[3] + dp[6]
    dp[6] = dp[3] + dp[6]
    ---------------
    dp[0, 1] = dp[0, 1] + dp[4,5,6]
    dp[2, 3] = dp[0, 1]
    dp[4,5,6] = dp[2, 3] + dp[4,5, 6]
*/