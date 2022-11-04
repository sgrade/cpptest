// 81. Search in Rotated Sorted Array II
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>

using namespace std;


// Some ideas are from https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/1890619/An-unique-intuitive-approach-or-8(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {      
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        
        while (left <= right) {
            while (left < right && nums[left] == nums[left + 1]) {
                ++left;
            }
            while (left < right && nums[right - 1] == nums[right]) {
                --right;
            }
            
            mid = left + (right - left) / 2;
            if (nums[left] == target || nums[right] == target || nums[mid] == target) {
                return true;
            }
            
            if (nums[left] < nums[mid]) {
                if (nums[mid] > target && nums[left] < target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            
            else {
                if (nums[mid] < target && target < nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};
