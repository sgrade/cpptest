// 2874. Maximum Value of an Ordered Triplet II
// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Greedy
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int n = nums.size();
            long long ans = 0, max_left = 0, max_diff = 0;
            for (int k = 0; k < n; ++k) {
                ans = max(ans, max_diff * nums[k]);
                max_diff = max(max_diff, max_left - nums[k]);
                max_left = max(max_left, 1LL * nums[k]);
            }
            return ans;
        }
    };
