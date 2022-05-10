// D. X-Sum

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (vector<int> &v: a) {
            for (int &el: v) cin >> el;
        }

        int ans = 0;

        int d = n + m - 1;

        for (int i = 0; i < n; ++i) {

            for (int j = 0; j < m; ++j) {

                int cur_ans = a[i][j];
                
                int r = i - 1, c = j - 1;
                while (r > -1 && c > -1) {
                    cur_ans += a[r][c];
                    --r;
                    --c;
                }

                r = i - 1, c = j + 1;
                while (r > -1 && c < m) {
                    cur_ans += a[r][c];
                    --r;
                    ++c;
                }

                r = i + 1, c = j - 1;
                while (r < n && c > -1) {
                    cur_ans += a[r][c];
                    ++r;
                    --c;
                }

                r = i + 1, c = j + 1;
                while (r < n && c < m) {
                    cur_ans += a[r][c];
                    ++r;
                    ++c;
                }

                ans = max(ans, cur_ans);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
