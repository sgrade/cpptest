// C. Ticks
// NOT FINISHED

#include <iostream>
#include <algorithm>
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
        vector<vector<bool>> a(n, vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            for (int j = 0; j < m; ++j) {
                if (tmp[j] == '*') {
                    a[i][j] = true;
                }
            }
        }

        bool ans = true;

        vector<vector<bool>> v(n, vector<bool>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    continue;
                }


            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '*' && !v[i][j]) {
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
