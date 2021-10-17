// B. Groups

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(5));
        for (auto &el: a) {
            for (auto &digit: el) {
                cin >> digit;
            }
        }

        bool ans = false;

        // Editorial - https://codeforces.com/blog/entry/95890
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == j) {
                    continue;
                }

                int cnt_i = 0, cnt_j = 0, cnt_both = 0;

                for (int x = 0; x < n; ++x) {
                    if (a[x][i] == 1) {
                        ++cnt_i;
                    }
                    if (a[x][j] == 1) {
                        ++cnt_j;
                    }

                    // Idea - https://codeforces.com/contest/1598/submission/131403270
                    if (a[x][i] == 1 && a[x][j] == 1) {
                        ++cnt_both;
                    }
                }

                if (cnt_i >= n / 2 && cnt_j >= n / 2  && (cnt_i + cnt_j - cnt_both) == n) {
                    ans = true;
                    goto ANS;
                }
            }
        }

        ANS:
        cout << (ans ? "YES": "NO") << '\n';
    }

    return 0;
}
