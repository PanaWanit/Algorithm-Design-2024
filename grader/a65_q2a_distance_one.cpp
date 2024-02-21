#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int M = 1e8+7;
int dp[N], qs[N];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    qs[0] = 1; // cumulative sum for bit string length less than or equal i that end with 1
    qs[1] = 2; // from empty and "1" string
    dp[1] = 1; // bit string length i that end with 0
    for(int i=2; i<=n; i++) {
        dp[i] = (dp[i-1] + qs[i-1] - qs[i-2] + M)%M; // can add 0 after 1,0
        int end1 = qs[max(i-k, 0)]; // can add 1 after length is far from 1 = k
        qs[i] = (qs[i-1] + end1)%M;
    }

    cout << (dp[n] + (qs[n] - qs[n-1])%M + M )%M << "\n";
    return 0;
}