// 2460. Apply Operations to an Array
// https://leetcode.com/problems/apply-operations-to-an-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), i = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (nums[j] != 0 && nums[j] == nums[j + 1]) {
                nums[j] *= 2;
                nums[j + 1] = 0;
            }
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        if (nums[i] == 0 && nums[n - 1] != 0)
            swap(nums[i], nums[n - 1]);
        return nums;
    }
};
