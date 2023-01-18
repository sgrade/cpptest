// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Dynamic Programming, Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], current_ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            current_ans = max(nums[i], current_ans + nums[i]);
            ans = max(current_ans, ans);
        }
        return ans;
    }
};
