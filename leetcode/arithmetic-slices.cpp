// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n < 3)
            return 0;
        int diff = nums[1] - nums[0], cur_len = 2;
        for (int i = 2; i < n; ++i) {
            int cur_diff = nums[i] - nums[i - 1];
            if (cur_diff == diff)
                ans += ++cur_len - 2;
            else
                cur_len = 2;
            diff = cur_diff; 
        }
        return ans;
    }
};
