// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Two Pointers
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % MOD;

        int ans = 0, left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans += power[right - left];
                ans %= MOD;
                ++left;
            }
            else
                --right;
        }

        return ans;
    }

private:
    const int MOD = 1e9 + 7;
};
