// A. Array Balancing

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int &el: a) {
            cin >> el;
        }
        for (int &el: b) {
            cin >> el;
        }

        ll aa = 0, bb = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
        }

        for (int i = 1; i < n; ++i) {
            aa += abs(a[i-1] - a[i]);
            bb += abs(b[i-1] - b[i]);
        }

        cout << aa + bb << '\n';
    }

    return 0;
}
