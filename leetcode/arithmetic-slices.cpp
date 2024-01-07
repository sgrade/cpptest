// 413. Arithmetic Slices
// https://leetcode.com/problems/arithmetic-slices/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        n = nums.size();
        if (n < 3)
            return 0;
        check(nums, 2, nums[1] - nums[0], 2);
        return ans;
    }
private:
    int n;
    int ans = 0;
    void check(vector<int>& nums, int idx, int diff, int cur_len) {
        if (idx == n)
            return;
        int cur_diff = nums[idx] - nums[idx - 1];
        if (cur_diff == diff)
            ans += ++cur_len - 2;
        else
            cur_len = 2;
        check (nums, idx + 1, cur_diff, cur_len);
    }
};
