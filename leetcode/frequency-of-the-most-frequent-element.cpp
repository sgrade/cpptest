// 1838. Frequency of the Most Frequent Element
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Sliding Window
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, ans = 1;
        long sum = nums[left], target;
        for (int right = 1; right < n; ++right) {
            target = nums[right];
            sum += target;
            while ((right - left + 1) * target - sum > k) {
                sum -= nums[left];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
