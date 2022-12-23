// 259. 3Sum Smaller
// https://leetcode.com/problems/3sum-smaller/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Two Pointers
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            ans += TwoSum(nums, target - nums[i], i + 1, n - 1);
        }
        return ans;
    }
private:
    int TwoSum(vector<int>& nums, const int& target, int left, int right) {
        int sm = 0;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                sm += right - left;
                ++left;
            }
            else {
                --right;
            }
        }
        return sm;
    }
};
