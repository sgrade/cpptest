// 34. Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mid;
        bool found = false;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] == target) {
                found = true;
                break;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        if (!found) {
            return {-1, -1};
        }
        
        left = mid, right = mid;
        while (left > 0 && nums[left - 1] == target) {
            --left;
        }
        while (right < n - 1 && nums[right + 1] == target) {
            ++right;
        }
        
        return  {left, right};
    }
};
