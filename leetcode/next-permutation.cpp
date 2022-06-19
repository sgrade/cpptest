// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        bool found = false;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
