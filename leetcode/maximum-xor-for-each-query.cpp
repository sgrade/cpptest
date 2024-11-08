// 1829. Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Prefix Array + Bit Masking
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        for (int i = 1; i < n; ++i)
            nums[i] ^= nums[i - 1];
        vector<int> ans(n);
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < n; ++i) {
            int current_xor = nums[n - 1 - i];
            ans[i] = current_xor ^ mask;
        }
        return ans;
    }
};
