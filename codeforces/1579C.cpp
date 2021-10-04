// C. Ticks

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        string tmp;
        vector<vector<bool>> a(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            for (int j = 0; j < m; ++j) {
                if (tmp[j] == '*') {
                    a[i][j] = true;
                }
            }
        }

        bool ans = true;

        vector<vector<bool>> v(n, vector<bool>(m, false));

        for (int i = n-1; i > -1; --i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    continue;
                }

                // Editorial - https://codeforces.com/blog/entry/95447
                int h = 1;
                while (i - h > -1) {
                    if (j - h < 0 || j + h > m - 1) {
                        break;
                    }
                    if (!a[i-h][j-h] || !a[i-h][j+h]) {
                        break;
                    }
                    ++h;
                }
                --h;

                if (h >= k) {
                    for (int d = 0; d <= h; ++d) {
                        v[i-d][j-d] = true;
                        v[i-d][j+d] = true;
                    }
                }

            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] && !v[i][j]) {
                    ans = false;
                    goto BRK;
                }
            }
        }

        BRK:
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
