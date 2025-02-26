// 1749. Maximum Absolute Sum of Any Subarray
// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Greedy - Prefix Sum
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int min_prefix_sum = INT_MAX, max_prefix_sum = INT_MIN;
        int prefix_sum = 0, max_abs_sum = 0;
        for (const int& num: nums) {
            prefix_sum += num;
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
            max_prefix_sum = max(max_prefix_sum, prefix_sum);
            if (prefix_sum >= 0)
                max_abs_sum = max(max_abs_sum, max(prefix_sum, prefix_sum - min_prefix_sum));
            else
                max_abs_sum = max(max_abs_sum, max(abs(prefix_sum), abs(prefix_sum - max_prefix_sum)));
        }
        return max_abs_sum;
    }
};
