// 2441. Largest Positive Integer That Exists With Its Negative
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

#include <bits/stdc++.h>

using namespace std;


// Based on a sample solution
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right && nums[left] < 0 && nums[right] > 0) {
            int candidate = abs(nums[left]);
            if (candidate == nums[right])
                return candidate;
            if (candidate > nums[right])
                ++left;
            else
                --right;
        }
        return -1;
    }
};
