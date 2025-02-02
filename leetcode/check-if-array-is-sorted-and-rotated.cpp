// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size(), i = 1;
        for (; i < n; ++i) {
            if (nums[i - 1] > nums[i])
                break;
        }
        if (i == n)
            return true;

        ++i;
        for (; i < n; ++i) {
            if (nums[i - 1] > nums[i])
                break;
        }

        return i == n && nums[0] >= nums[n - 1];
    }
};
