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
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        for (int right = 0; right < nums.size(); ++right) {
            for (int left = 0; left < right; ++left) {
                diff = nums[right] - nums[left];
                dp[right][diff] =  dp[left].find(diff) == dp[left].end() ? 2 : dp[left][diff] + 1;
                ans = max(ans, dp[right][diff]);
            }
        }
        return ans;
    }
};
