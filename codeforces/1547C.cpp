// C. Pair Programming

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }

        bool ans = true;
        vector<int> output(n+m, 0);

        int idx_a = 0, idx_b = 0;
        for (int i = 0; i < n+m; ++i) {

            if (idx_a < n && a[idx_a] == 0) {
                ++k;
                ++idx_a;
                continue;
            }
            else if (idx_b < m && b[idx_b] == 0) {
                ++k;
                ++idx_b;
                continue;
            }

            if (a[idx_a] > k && b[idx_b] > k) {
                ans = false;
                break;
            }

            else {
                if (idx_a < n && a[idx_a] <= k) {
                    output[i] = a[idx_a];
                    ++idx_a;
                }

                else if (idx_b < m && b[idx_b] <= k) {
                    output[i] = b[idx_b];
                    ++idx_b;
                }

                else {
                    ans = false;
                    break;
                }
            }

        }

        if (ans) {
            for (auto &el: output) {
                cout << el << ' ';
            }
            cout << endl;
        }

        else {
            cout << "-1" << endl;
        }

    }

    return 0;
}
