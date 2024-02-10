#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 8;
int A[N][N];

void gen(int a, int b, int top, int bottom, int left, int right) {
    if(a == 0) {
        // top == bottom && left == right
        A[top][left] = b;
        return;
    }
    int mi = (top + bottom) / 2 , mj = (left + right) / 2;
    gen(a-1, b, top, mi, left, mj);
    gen(a-1, b-1, top, mi, mj+1, right);
    gen(a-1, b+1, mi+1, bottom, left, mj);
    gen(a-1, b, mi+1, bottom, mj+1, right);

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int a,b;
    cin >> a >> b;

    gen(a, b, 0, (1<<a) - 1, 0, (1<<a) - 1);
    for(int i=0; i<1<<a; i++) {
        for(int j=0; j<1<<a; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    return 0;
}