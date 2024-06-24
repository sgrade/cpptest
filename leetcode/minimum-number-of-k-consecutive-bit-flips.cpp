// 995. Minimum Number of K Consecutive Bit Flips
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using an Auxiliary Array
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = nums.size();
        vector<bool> flipped(n);
        int valid_flips = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                if (flipped[i - k])
                    --valid_flips;
            }
            if (valid_flips % 2 == nums[i]) {
                if (i + k > n)
                    return -1;
                ++valid_flips;
                flipped[i] = true;
                ++ans;
            }
        }
        return ans;
    }
};
