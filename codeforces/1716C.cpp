// C. Robot in a Hallway
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int m;
        cin >> m;

        vector<vector<long long>> a(2, vector<long long>(m));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        long long ans = numeric_limits<int>::max(), cur_ans;

        // Top row left to right then bottom row right to left

        cur_ans = 0;
        vector<vector<long long>> top_then_bot(2, vector<long long>(m));
        for (int j = 1; j < m; ++j) {
            cur_ans = max(a[0][j] + 1, cur_ans + 1);
            top_then_bot[0][j] = cur_ans;
        }
        for (int j = m - 1; j >= 0; --j) {
            cur_ans = max(a[1][j] + 1, cur_ans + 1);
            top_then_bot[1][j] = cur_ans;
        }
        ans = min(cur_ans, ans);

        // Bottom row left to right then top right to left
        cur_ans = 0;
        vector<vector<long long>> bot_then_top(2, vector<long long>(m));
        for (int j = 0; j < m; ++j) {
            cur_ans = max(a[1][j] + 1, cur_ans + 1);
            bot_then_top[1][j] = cur_ans;
        }
        for (int j = m - 1; j > 0; --j) {
            cur_ans = max(a[0][j] + 1, cur_ans + 1);
            bot_then_top[0][j] = cur_ans;
        }
        ans = min(cur_ans, ans);


        // Start -> bottom -> right -> top -> right -> ...
        cur_ans = 0;
        int i = 0, j = 0;
        int cnt = 0, diff_i = 1;
        vector<vector<long long>> vertical(2, vector<long long>(m));
        while (true) {

            if (cnt % 2 == 0) {
                i += diff_i;
                diff_i = - diff_i;
            }
            else {
                ++j;
            }
            ++cnt;

            if (j == m) {
                break;
            }

            cur_ans = max(a[i][j] + 1, cur_ans + 1);
            vertical[i][j] = cur_ans;
        }
        ans = min(cur_ans, ans);

        // Decide if I need to keep walking up-down or switch to horizontal
        for (int j = 0; j < m; ++j) {
            if (j < m - 1) {
                cur_ans = (j % 2 == 0 ? top_then_bot[1][j] : top_then_bot[1][j + 1]);
                cur_ans -= top_then_bot[0][j] - vertical[0][j];
                ans = min(ans, cur_ans);
            }
        } 
        for (int j = 0; j < m; ++j) {
            if (j < m - 1) {
                cur_ans = (j % 2 == 0 ? bot_then_top[0][j + 1] : bot_then_top[0][j]);
                cur_ans -= bot_then_top[1][j] - vertical[1][j];
                ans = min(ans, cur_ans);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
