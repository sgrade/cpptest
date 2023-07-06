// 1027. Longest Arithmetic Subsequence
// https://leetcode.com/problems/longest-arithmetic-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int diff;
        vector<vector<int>> dp(n, vector<int>(1001));
        for (int right = 1; right < nums.size(); ++right) {
            for (int left = 0; left < right; ++left) {
                diff = 500 + nums[right] - nums[left];
                dp[right][diff] = max(2, dp[left][diff] + 1);
                ans = max(ans, dp[right][diff]);
            }
        }
        return ans;
    }
};
