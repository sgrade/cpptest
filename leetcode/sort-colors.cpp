// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_idx = 0, one_idx = 0, two_idx = nums.size() - 1;
        while (one_idx <= two_idx) {
            if (nums[one_idx] == 0)
                swap (nums[zero_idx++], nums[one_idx++]);
            else if (nums[one_idx] == 1)
                ++one_idx;
            else
                swap(nums[one_idx], nums[two_idx--]);
        }
    }
};
