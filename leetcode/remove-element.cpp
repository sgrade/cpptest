// 27. Remove Element
// https://leetcode.com/problems/remove-element/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                --right;
            }
            else {
                ++left;
            }
        }
        return right;
    }
};
