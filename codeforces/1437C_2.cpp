// C. Chef Monocarp

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int main() {

    int q;
    cin >> q;

    while (q--) {

        int n;
        cin >> n;

        vector<int> t(n);
        for (auto &el: t) {
            cin >> el;
            --el;
        }
        sort(begin(t), end(t));

        // Editorial - https://codeforces.com/blog/entry/84149
        // Below solution is based on "Solution 1" from the editorial
        vector<vector<int>> dp(n+1, vector<int>(2*n, numeric_limits<int>::max()));
        dp[0][0] = 0;

        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < 2*n-1; ++j) {
                if (dp[i][j] < numeric_limits<int>::max()) {
                    if (i < n) {
                        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(t[i] - j));
                    }
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                }
            }
        }

        cout << dp[n][2*n-1] << endl;

    }

    return 0;
}
