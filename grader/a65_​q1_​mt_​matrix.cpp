#include <bits/stdc++.h>
using namespace std;

int a[3][3];
const int di[]={-1,-1, 0 ,0}, dj[]={-1,0,-1,0};

int dc(long long x, long long y, long long sz) {
	if(sz == 2)
		return a[x][y];
	long long mi = sz >> 1LL;
	int quad = 2*(x > mi) + (y > mi);
	/* quad
	0 | 1
	-----
	2 | 3
	*/
	// try to move to quad 0
	if(quad == 0) return dc(x, y, mi); // already quad 0
	if(quad == 1) return dc(y-mi, x, mi); // transpose ( go left to quad 0 )
	if(quad == 2) return -dc(x-mi, y, mi); // -negative up (go up to quad 0)
	return -dc(y-mi, x-mi, mi); // tranpose -negative (go left and up to quad 0)
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	n = min(n+1, 60); // log2(10^18) ~ 60

	for(int i=0; i<4; i++)
		cin >> a[i/2 + 1][i%2 + 1];
	while(q--) {
		long long i, j;
		cin >> i >> j;
		cout << dc(i, j, 1LL<<n) << "\n";
	}
	return 0;
}