// 1062. Longest Repeating Substring
// https://leetcode.com/problems/longest-repeating-substring/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 5: Dynamic Programming
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max (ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
