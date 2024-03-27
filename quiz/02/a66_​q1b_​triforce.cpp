#include<bits/stdc++.h>
using namespace std;
const int N = 1<<8;
int a[N+10][N+10];

int solve(int si, int sj, int ei, int ej) {
    if(ei-si+1 == 2) {
        if(a[si+1][sj+1] != 0) return 0;
        if(a[si][sj] == 0 || a[si+1][sj] == 0 || a[si][sj+1] == 0) return 0;
        vector<int> cnt(4);
        cnt[a[si][sj]]++;
        cnt[a[si+1][sj]]++;
        cnt[a[si][sj+1]]++;
        if(cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1) return 0;
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }

    int mi = (si + ei)/2, mj = (sj + ej)/2;
     int d = 0;
    for(int i=mi+1; i<=ei; i++)
        for(int j=mj+1; j<=ej; j++) d += a[i][j];
    if(d != 0) return 0;
    int a = solve(si, sj, mi, mj);
    int b = solve(si, mj+1, mi, ej);
    int c = solve(mi+1, sj, ei, mj);
    if(a == 0 || b==0 || c==0) return 0;
   
    vector<int> cnt(4);
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    return max_element(cnt.begin(), cnt.end()) - cnt.begin();


}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int t=3; t--;) {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=n; j++) cin >> a[i][j];
        cout << solve(1, 1, n, n) << "\n";
    }
    return 0;
}