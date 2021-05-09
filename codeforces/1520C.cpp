// C. Not Adjacent Matrix

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        if (n == 1) {
            cout << 1 << endl;
        }

        else if (n == 2) {
            cout << -1 << endl;
        }

        else {
            vector<vector<int>> ans(n, vector<int>(n));

            vector<int> v1;
            vector<int> v2;
            for (int i = 1; i < n * n + 1; ++i) {
                if (i % 2 == 0) {
                    v2.push_back(i);
                }
                else {
                    v1.push_back(i);
                }
            }
            v1.insert(v1.end(), v2.begin(), v2.end());

            int idx = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j, ++idx) {
                    ans[i][j] = v1[idx];
                }
            }

            for (auto &v: ans) {
                for (auto &x: v) {
                    cout << x << ' ';
                }
                cout << endl;
            }
        }
    }

    return 0;
}
