// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// implementation with lower_bound

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        vector<int>::iterator it;
        it = lower_bound(nums.begin(), nums.end(), target);
        
        if (it == nums.end() || *it != target) {
            return {-1, -1};
        }
        
        int left = distance(nums.begin(), it);
        int right = left;
        while (right < nums.size() - 1 && nums[right + 1] == target) {
            ++right;
        }
        return  {left, right};
    }
};
