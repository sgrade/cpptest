// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid, right = nums.size() - 1;
        
        while (left < nums.size() && nums[left] == 0) ++left;
        while (right >= 0 && nums[right] == 2) --right;
        
        while (left < right) 
        {
            if (nums[left] == 1) 
            {
                mid = left + 1;
                while (mid <= right && nums[mid] == 1) ++mid;
                if (mid > right) break;
                swap (nums[left], nums[mid]);
            }
            else if (nums[left] == 2)
            {
                swap (nums[left], nums[right]); 
                --right;
            }
            if (nums[left] == 0) ++left;
        }
    }
};
