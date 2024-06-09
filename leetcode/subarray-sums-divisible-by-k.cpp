// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Prefix Sums and Counting
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        vector<int> mods(k);
        mods[0] = 1;

        int prefix_mod = 0, ans = 0;
        for (const int& num: nums) {
            prefix_mod += num % k + k;
            prefix_mod %= k;
            ans += mods[prefix_mod];
            ++mods[prefix_mod];
        }

        return ans;
    }
};
