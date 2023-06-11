// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Intelligently Build a Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> sub = {nums[0]};
        for (int i = 1; i < n; ++i) {
            if (nums[i] > sub.back())
                sub.emplace_back(nums[i]);
            else {
                int j = 0;
                while (nums[i] > sub[j])
                    ++j;
                sub[j] = nums[i];
            }
        }
        return sub.size();
    }
};
