// 2393. Count Strictly Increasing Subarrays
// https://leetcode.com/problems/count-strictly-increasing-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Greedy
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            long current = 1;
            while (i + 1 < n && nums[i] < nums[i + 1]) {
                ++current;
                ++i;
            }
            ans += (current * (current + 1)) / 2;
        }
        return ans;
    }
};
