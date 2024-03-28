// 2958. Length of Longest Subarray With at Most K Frequency
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Counting and Sliding Window
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int ans = 0;
        int left = 0, right = 0;
        unordered_map<int, int> counter;
        while (right < nums.size()) {
            ++counter[nums[right]];
            while (counter[nums[right]] > k)
                --counter[nums[left++]];
            ans = max(ans, right - left + 1);
            ++right;
        }
        return ans;
    }
};
