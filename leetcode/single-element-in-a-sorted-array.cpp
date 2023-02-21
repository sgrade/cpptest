// 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Binary Search on Evens Indexes Only
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (mid % 2 == 1) --mid;
            if (nums[mid] == nums[mid + 1]) left = mid + 2;
            else right = mid;
        }
        return nums[left];
    }
};
