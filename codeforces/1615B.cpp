// B. And It's Non-Zero

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    // Key ideas from https://codeforces.com/contest/1615/submission/140448127
    vector<vector<int>> dp(30, vector<int>(2e5 + 1));
    int bt, bt_set;
    for (int i = 0; i < 30; ++i) {
        // i-th bit set to one
        bt = 1 << i;
        for (int j = 0; j < 2e5 + 1; ++j) {
            bt_set = bt & j ? 0 : 1;
            dp[i][j + 1] = dp[i][j] + bt_set;
        }
    }
    
    int t;
    cin >> t;

    while (t--) {

        int l, r;
        cin >> l >> r;

        // Editorial - https://codeforces.com/blog/entry/98253
        int ans = r - l + 1;
        for (int i = 0; i < 30; ++i) {
            ans = min(ans, dp[i][r + 1] - dp[i][l]);
        }
        cout << ans << '\n';
    }

    return 0;
}
