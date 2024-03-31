// 2444. Count Subarrays With Fixed Bounds
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Two Pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long long ans = 0;
        int cur_min = -1, cur_max = -1, left_bound = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                left_bound = i;
            if (nums[i] == minK)
                cur_min = i;
            if (nums[i] == maxK)
                cur_max = i;
            ans += max(0, min(cur_max, cur_min) - left_bound);
        }
        return ans;
    }
};
