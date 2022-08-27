// C. Min-Max Array Transformation

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n), b(n), mins(n), maxs(n);

        for (int &el: a) cin >> el;
        for (int &el: b) cin >> el;

        int idx_a = 0, idx_b = 0;
        while (idx_a < n) {
            while (b[idx_b] < a[idx_a]) {
                ++idx_b;
            }
            mins[idx_a] = b[idx_b] - a[idx_a];
            ++idx_a;
        }

        maxs[n - 1] = b[n - 1] - a[n - 1];
        idx_a = n - 2, idx_b = n - 1;
        while (idx_a >= 0) {
            if (a[idx_a + 1] + mins[idx_a + 1] > b[idx_a]) {
                idx_b = idx_a;
            }
            maxs[idx_a] = b[idx_b] - a[idx_a];
            --idx_a;
        }

        for (int &el: mins) cout << el << ' ';
        cout << '\n';
        for (int &el: maxs) cout << el << ' ';
        cout << '\n';
    }

    return 0;
}
