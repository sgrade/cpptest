// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int left = 0, n = nums.size(), right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else {
                ans[0] = distance(nums.begin(), lower_bound(nums.begin() + left, nums.begin() + mid + 1, target));
                ans[1] = distance(nums.begin(), upper_bound(nums.begin() + mid, nums.begin() + right + 1, target)) - 1;
                break;
            }
        }
        return ans;
    }
};
