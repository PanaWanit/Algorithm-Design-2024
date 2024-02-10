#include <bits/stdc++.h>
using namespace std;

const int N = 1<<10;
const int d[] = {-1, 1}, di[]={-1,-1, 0 ,0}, dj[]={-1,0,-1,0};

using tp = tuple<int,int,int>;
vector<tp> ans;

void tile(int n, int ni, int nj, int mi, int mj) {
	if(n==1) return;
	int q = 2*(ni>=mi) + (nj>=mj);
	ans.emplace_back(q, mj-1, mi-1);
	for(int i=0; i<4; ++i) {
		if(i==q) tile(n/2, ni, nj, mi+d[i/2]*n/4, mj+d[i&1]*n/4);
		else tile(n/2, mi+di[i], mj+dj[i], mi+d[i/2]*n/4, mj+d[i&1]*n/4);
	}
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n,x,y;
    cin >> n >> x >> y;
    tile(n, y, x, n/2, n/2);

    cout << ans.size() << "\n";
    for(auto& [orient, x, y] : ans) 
        cout << orient << " " << x << " " << y << "\n";
    return 0;
}