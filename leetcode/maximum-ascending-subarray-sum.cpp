// 1800. Maximum Ascending Subarray Sum
// https://leetcode.com/problems/maximum-ascending-subarray-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = nums[0], current_ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] >= nums[i])
                current_ans = nums[i];
            else
                current_ans += nums[i];
            ans = max(ans, current_ans);
        }
        return ans;
    }
};
