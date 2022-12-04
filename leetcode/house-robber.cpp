// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>

using namespace std;


// Similar to Leetcode's Approach 3: Optimized Dynamic Programming
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int rob_i_minus_two = 0, rob_i_minus_one = nums[0], current;
        for (int i = 1; i < n; ++i) {
            current = max(rob_i_minus_two + nums[i], rob_i_minus_one);
            rob_i_minus_two = rob_i_minus_one;
            rob_i_minus_one = current;
        }
        return rob_i_minus_one;
    }
};
