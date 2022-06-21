// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], cur_ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cur_ans = max(nums[i], cur_ans + nums[i]);
            ans = max(ans, cur_ans);
        }
        return ans;
    }
};
