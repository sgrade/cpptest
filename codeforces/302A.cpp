// A. Eugeny and Array

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int tmp, positives = 0, negatives = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp > 0) ++positives;
        else ++negatives;
    }

    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        if ((r - l + 1) % 2 == 0 && (r - l + 1) / 2 <= min(negatives, positives)) {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }

    return 0;
}
