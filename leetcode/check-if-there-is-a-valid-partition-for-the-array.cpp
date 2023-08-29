// 2369. Check if There is a Valid Partition For The Array
// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Space Optimized Bottom-Up Dynamic Programming
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3);
        dp[0] = 1;

        for (int i = 0; i < n; ++i) {
            int dp_idx = i + 1;
            bool ans = false;
            if (i > 0 && nums[i] == nums[i - 1])
                ans |= dp[(dp_idx - 2) % 3];
            if (i > 1 && nums[i] == nums[i - 1] && nums[i] == nums[i - 2])
                ans |= dp[(dp_idx - 3) % 3];
            if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2)
                ans |= dp[(dp_idx - 3) % 3];
            
            dp[dp_idx % 3] = ans;
        }

        return dp[n % 3];
    };
};
