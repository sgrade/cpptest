// 3202. Find the Maximum Length of Valid Subsequence II
// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/

#inclide <bits/stdc++.h>

using namespace std;


// Based on Editorial's Find the Maximum Length of Valid Subsequence II
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> dp(k, vector<int>(k));
        int ans = 0;
        for (int& num: nums) {
            num %= k;
            for (int prev = 0; prev < k; ++prev) {
                dp[prev][num] = dp[num][prev] + 1;
                ans = max(ans, dp[prev][num]);
            }
        }
        return ans;
    }
};
