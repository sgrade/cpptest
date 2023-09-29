// 896. Monotonic Array
// https://leetcode.com/problems/monotonic-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int min_so_far = nums[0], max_so_far = nums[0];
        bool mono_increase = true, mono_decrease = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < max_so_far)
                mono_increase = false;
            if (nums[i] > min_so_far)
                mono_decrease = false;
            min_so_far = min(min_so_far, nums[i]);
            max_so_far = max(max_so_far, nums[i]);
        }
        return mono_increase || mono_decrease ? true : false;
    }
};
