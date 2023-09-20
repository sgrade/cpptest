// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int ans = 1e5 + 1;
        
        int left = 0, right = 0, sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum > target && left <= right) {
                sum -= nums[left];
                ++left;
            }
            if (sum == target)
                ans = min(ans, n - (right - left + 1));
            ++right;
        }
        
        return ans == 1e5 + 1 ? -1 : ans;
    }
};
