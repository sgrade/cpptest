// 523. Continuous Subarray Sum
// https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Prefix Sum and Hashing
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        // <prefix_sum_modulo, idx>
        unordered_map<int, int> seen;
        seen[0] = -1;

        int prefix_mod = 0;
        for (int i = 0; i < n; ++i) {
            prefix_mod += nums[i];
            prefix_mod %= k;
            if (seen.find(prefix_mod) != seen.end()) {
                if  (i - seen[prefix_mod] > 1)
                    return true;
            }
            else
                seen[prefix_mod] = i;
        }
        return false;
    }
};
