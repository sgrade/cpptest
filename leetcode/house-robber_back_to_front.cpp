// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Optimized Dynamic Programming
// Iterating from back to front
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int rob_i_plus_one = nums[n - 1], rob_i_plus_two = 0, current;
        for (int i = n - 2; i >= 0; --i) {
            current = max(rob_i_plus_one, rob_i_plus_two + nums[i]);
            rob_i_plus_two = rob_i_plus_one;
            rob_i_plus_one = current;
        }
        return rob_i_plus_one;
    }
};
