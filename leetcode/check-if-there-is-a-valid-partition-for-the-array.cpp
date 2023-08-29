// 2369. Check if There is a Valid Partition For The Array
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-Up Dynamic Programming
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            int dp_idx = i + 1;
            if (i > 0 && nums[i] == nums[i - 1])
                dp[dp_idx] |= dp[dp_idx - 2];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                dp[dp_idx] |= dp[dp_idx - 3];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                dp[dp_idx] |= dp[dp_idx - 3];
        }

        return dp[n];
    };
};
