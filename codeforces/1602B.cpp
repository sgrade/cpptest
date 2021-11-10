// B. Divine Array

#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i < n+1; ++i) {
            cin >> a[i];
        }

        // Explanation - https://www.youtube.com/watch?v=TalRAuB0Dfg

        vector<vector<int>> dp(n+1, vector<int>(n+1));
        dp[0] = a;

        for (int i = 1; i < n+1; ++i) {
            
            map<int, int> cnt;
            for (int j = 1; j < n+1; ++j) {
                ++cnt[dp[i-1][j]];
            }

            for (int j = 1; j < n+1; ++j) {
                dp[i][j] = cnt[dp[i-1][j]];
            }
        }

        int q;
        cin >> q;

        while (q--) {

            int x, k;
            cin >> x >> k;
            k = min(n, k);

            cout << dp[k][x] << endl;
        }

    }

    return 0;
}
