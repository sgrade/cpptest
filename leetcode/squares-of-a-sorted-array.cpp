// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        vector<int> ans(n);
        int ans_idx = n - 1;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right]))
                ans[ans_idx--] = nums[right] * nums[right--];
            else
                ans[ans_idx--] = nums[left] * nums[left++];
        }
        return ans;
    }
};
