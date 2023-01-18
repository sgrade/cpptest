// 918. Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Calculate the "Minimum Subarray"
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, current_min = 0, current_max = 0, mx = nums[0], mn = nums[0];
        for (const int& num: nums) {
            total += num;
            current_max = max(current_max, 0) + num;
            mx = max(mx, current_max);
            current_min = min(current_min, 0) + num;
            mn = min(mn, current_min);
        }
        return total == mn ? mx : max(mx, total - mn);
    }
};
