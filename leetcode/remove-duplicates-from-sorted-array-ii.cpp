// 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Popping Unwanted Duplicates
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return n;
        }
        
        int left = 1, cnt = 1;
        while (left < n) {
            if (nums[left] == nums[left - 1]) {
                ++cnt;
                if (cnt > 2) {
                    nums.erase(nums.begin() + left);
                    --n;
                    --left;
                }
            }
            
            else {
                cnt = 1;
            }
            
            ++left;
        }
        
        return n;
    }
};
