// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Index as a Hash Key
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        bool one_present = false;
        for (int& num: nums) {
            if (num == 1)
                one_present = true;
            if (num <= 0 || num > n)
                num = 1;
        }
        if (!one_present)
            return 1;

        for (int i = 0; i < n; ++i) {
            int value = abs(nums[i]);
            if (value == n)
                nums[0] = -abs(nums[0]);
            else
                nums[value] = -abs(nums[value]);
        }

        for (int i = 1; i < n; ++i) {
            if (nums[i] > 0)
                return i;
        }
        if (nums[0] > 0)
            return n;
        return n + 1;
    }
};
