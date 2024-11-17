// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Sliding Window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int left = 0, right, sum = 0;
        int ans = numeric_limits<int>::max();
        for (right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return ans == numeric_limits<int>::max() ? 0 : ans;
    }
};
