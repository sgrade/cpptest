// 2270. Number of Ways to Split Array
// https://leetcode.com/problems/number-of-ways-to-split-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Prefix Sum Array
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        vector<long long> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            long long left = prefix_sum[i], 
            right = prefix_sum[n - 1] - prefix_sum[i];
            if (left >= right)
                ++ans;
        }
        return ans;
    }
};
