// 2873. Maximum Value of an Ordered Triplet I
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 4: Greedy
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size(), max_left = 0, max_diff = 0;
            long long ans = 0;
            for (int k = 0; k < n; ++k) {
                ans = max(ans, 1LL * max_diff * nums[k]);
                max_diff = max(max_diff, max_left - nums[k]);
                max_left = max(max_left, nums[k]);
            }
            return ans;
        }
    };
