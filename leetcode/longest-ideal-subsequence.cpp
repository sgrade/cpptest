// 2370. Longest Ideal Subsequence
// https://leetcode.com/problems/longest-ideal-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Iterative Dynamic Programming
class Solution {
public:
    int longestIdealString(string s, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        int n = s.size();
        vector<int> dp(26, 0);

        for (int i = 0; i < n; ++i) {
            int cur = s[i] - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; ++prev) {
                if (abs(prev - cur) <= k)
                    best = max(best, dp[prev]);
            }
            dp[cur] = max(dp[cur], best + 1);
        }
        for (const int& x: dp)
            ans = max(ans, x);

        return ans;
    }
};
