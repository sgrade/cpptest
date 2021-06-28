// C. Challenging Cliffs

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> h(n);
        for (auto &el: h) {
            cin >> el;
        }

        sort(begin(h), end(h));

        vector<int> ans;

        int d = numeric_limits<int>::max();
        int idx1, idx2;

        for (int i = 1; i < n; ++i) {
            if (h[i] - h[i-1] < d) {
                idx1 = i-1;
                idx2 = i;
                d = h[idx2] - h[idx1];
            }
        }

        // First
        cout << h[idx1] << ' ';

        // Editorial - https://codeforces.com/blog/entry/91381
        for (int i = idx1 + 1; i < n; ++i) {
            if (i == idx2) {
                continue;
            }
            cout << h[i] << ' ';
        }
        for (int i = 0; i < idx1; ++i) {
            cout << h[i] << ' ';
        }

        // Last
        cout << h[idx2] << ' ' << endl;
    }

    return 0;
}
