// 1027. Longest Arithmetic Subsequence
// https://leetcode.com/problems/longest-arithmetic-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming
// TLE
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int, map<int, int>> dp;
        for (int right = 0; right < nums.size(); ++right) {
            for (int left = 0; left < right; ++left) {
                int diff = nums[right] - nums[left];
                auto it = dp[left].find(diff);
                if (it == dp[left].end()) {
                    dp[right][diff] = 2;
                }
                else 
                    dp[right][diff] = dp[left][diff] + 1;
                ans = max(ans, dp[right][diff]);
            }
        }
        return ans;
    }
};
