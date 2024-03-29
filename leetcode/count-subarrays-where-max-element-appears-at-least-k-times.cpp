// 2962. Count Subarrays Where Max Element Appears at Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Track Indexes of Max Element
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int max_el = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        vector<int> indexes;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_el)
                indexes.emplace_back(i);
            int freq = indexes.size();
            if (freq >= k)
                ans += indexes[freq - k] + 1;
        }
        return ans;
    }
};
