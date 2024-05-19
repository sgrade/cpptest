// 3068. Find the Maximum Sum of Node Values
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/


#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming - Memoization
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = nums.size();
        memo.resize(n, vector<long long>(2));
        return GetSum(0, 1, nums, k);
    }

private:
    int n;
    vector<vector<long long>> memo;
    long long GetSum(int idx, int is_even, const vector<int>& nums, const int& k) {
        if (idx == nums.size())
            return is_even == 1 ? 0 : INT_MIN;
        if (memo[idx][is_even])
            return memo[idx][is_even];
        long long no_xor = nums[idx] + GetSum(idx + 1, is_even, nums, k);
        long long with_xor = (nums[idx] ^ k) + GetSum(idx + 1, is_even ^ 1, nums, k);
        return memo[idx][is_even] = max(no_xor, with_xor);
    }
};
