// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // dp - length of the longest common sequence (lcs)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    continue;
                }
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // return total lenght - length of lcs
        return n + m - 2 * dp[n][m];
    }
};


int main() {

    return 0;
}
