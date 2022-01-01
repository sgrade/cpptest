// B. Build the Permutation

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        // Editorial - https://codeforces.com/blog/entry/97782
        if ((a + b) + 2 > n || abs(a - b) > 1) {
            cout << "-1" << endl;
            continue;
        }

        bool replace = false;
        if (a < b) {
            swap(a, b);
            replace = true;
        }

        // Some implementation ideas - https://codeforces.com/contest/1608/submission/138730741
        vector<int> p(n);
        for (int i = 0; i < a; ++i) {
            p[2 * i] = i + 1;
            p[2 * i + 1] = n - i;
        }

        if (a == b) {
            for (int i = 2 * a; i < n; ++i) {
                p[i] = i - a + 1;
            }
        }

        else {
            for (int i = 2 * a; i < n; ++i) {
                p[i] = n + a - i;
            }
            if (replace) {
                for (int i = 0; i < n; ++i) {
                    p[i] = n - p[i] + 1;
                }
            }
        }
        

        for (auto &el: p) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
