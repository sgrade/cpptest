// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Dynamic Programming
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(max_in_line(nums, 0, n - 1), max_in_line(nums, 1, n));
    }
private:
    int max_in_line (vector<int> &nums, const int left, const int right) {
        int before_prev = 0, prev = nums[left], current;
        for (int i = left + 1; i < right; ++i) {
            current = max(prev, before_prev + nums[i]);
            before_prev = prev;
            prev = current;
        }
        return current;
    }
};
