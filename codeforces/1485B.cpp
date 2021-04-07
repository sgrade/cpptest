// B. Replace and Keep Sorted

#include <iostream>

using namespace std;


int main() {

    int n, q, k;
    cin >> n >> q >> k;

    int a[n];
    for (auto &el: a) {
        cin >> el;
    }
    
    int l, r;
    // Editorial - https://codeforces.com/blog/entry/87470
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        --l;
        --r;
        cout << (a[l] - 1) + (k - a[r]) + 2 * ((a[r] - a[l]) - (r - l)) << endl;
    }

    return 0;
}
