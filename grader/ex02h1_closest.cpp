#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+1;
using point = pair<int, int>;

point a[N];

int pow2(const int& a) {
    return a * a;
}
int distance(const point& a, const point& b) {
    return pow2(a.first - b.first) + pow2(a.second - b.second);
}

int cmpY(const point& a, const point& b) {
    return a.second < b.second;
}

int closet_pair(int l, int r) {
    int mn = 2e9;
    if(r - l + 1 <= 3) {
        for(int i=l; i<=r; i++) {
            for(int j=i+1; j <= r; j++) {
                mn = min(mn, distance(a[i], a[j]));
            }
        }
        return mn;
    }
    int mid = (l + r) / 2;
    int dl = closet_pair(l, mid), dr = closet_pair(mid+1, r);
    mn = min(dl, dr);
    vector<point> closet_point;
    for(int i=l; i<=r; i++) {
        if(abs(a[i].first - a[mid].first) < mn) closet_point.push_back(a[i]);
    }
    sort(closet_point.begin(), closet_point.end(), cmpY);
    int n = closet_point.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n && closet_point[j].second - closet_point[i].second < mn; j++)
            mn = min(mn, distance(closet_point[i], closet_point[j]));
    }

    return mn;

}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    cout << closet_pair(0, n-1) << "\n";
    return 0;
}