// 2563. Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;

        int x;
        for (int i = 0; i < n; ++i) {
            x = lower - nums[i];
            auto left_it = lower_bound(nums.begin() + i + 1, nums.end(), x);
            x = upper - nums[i];
            auto right_it = upper_bound(nums.begin() + i + 1, nums.end(), x);
            int d = distance(left_it, right_it);
            ans += d;
        }
        return ans;
    }
};
