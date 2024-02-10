#include <bits/stdc++.h>
using namespace std;

vector<int> seq_size;

char divide_conquer(int pos, int n) {
    if(seq_size[n-1] < pos && pos <= seq_size[n-1] + n + 3)
        return pos == seq_size[n-1] + 1 ? 'g' : 'a';
    if(pos <= seq_size[n - 1])
        return divide_conquer(pos, n-1);
    if(pos > seq_size[n-1] + n + 3)
        return divide_conquer(pos - (seq_size[n-1] + n + 3), n-1);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    // let a(n) be the size of sequence
    // a(n) = 2 * a(n-1) + 3 + n
    // a(0) = 3

    seq_size.push_back(3);
    for(int i=1; seq_size.back() <= (int)1e9; i++)
        seq_size.push_back(seq_size.back() * 2 + 3 + i);
    
    int n;
    cin >> n;
    
    cout << divide_conquer(n, seq_size.size()-1) << "\n";
    return 0;
}