// 1248. Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Sliding Window (Space Optimisation of queue-based approach)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size(), ans = 0;
        int odd = 0, left = 0, arrays = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] % 2 == 1)
                ++odd;
            if (odd == k) {
                arrays = 0;
                while (odd == k) {
                    odd -= nums[left] % 2;
                    ++arrays;
                    ++left;
                }
            }
            ans += arrays;
        }
        return ans;
    }
};
