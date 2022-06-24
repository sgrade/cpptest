// C. Zero Path
 
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
int n, m;
 
bool ans;
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
 
    while (t--) {
 
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
 
        ans = false;
 
        // Editorial - https://codeforces.com/blog/entry/103996
        if ((n + m) % 2 != 0) {

            // https://www.youtube.com/watch?v=90YSRIreNLY
            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
            dp[0][0].first = a[0][0];
            dp[0][0].second = a[0][0];
            for (int j = 1; j < m; ++j) {
                dp[0][j].first = dp[0][j - 1].first + a[0][j];
                dp[0][j].second = dp[0][j - 1].second + a[0][j];
            }
            for (int i = 1; i < n; ++i) {
                dp[i][0].first = dp[i - 1][0].first + a[i][0];
                dp[i][0].second = dp[i - 1][0].first + a[i][0];
            }
            for (int i = 1; i < n; ++i) {
                for (int j = 1; j < m; ++j) {
                    dp[i][j].first = min(dp[i][j - 1].first, dp[i - 1][j].first) + a[i][j];
                    dp[i][j].second = max(dp[i][j - 1].second, dp[i - 1][j].second) + a[i][j];
                }
            }

            if (dp[n - 1][m - 1].first <= 0 && dp[n - 1][m - 1].second >= 0) {
                ans = true;
            }
        }
 
        cout << (ans ? "YES\n" : "NO\n");
    }
 
    return 0;
}
