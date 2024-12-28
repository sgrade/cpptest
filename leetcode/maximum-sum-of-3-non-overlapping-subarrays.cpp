// 689. Maximum Sum of 3 Non-Overlapping Subarrays
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Memoization
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // subarray starting positions
        this->n = nums.size() - k + 1;
        this->k = k;

        sums.resize(n);
        int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += nums[i];
        sums[0] = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum = sum - nums[i - k] + nums[i];
            sums[i - k + 1] = sum;
        }

        memo.resize(n, vector<int>(4, -1));

        dp(0, 3);
        dfs(0, 3);
        return indexes;
    }

private:
    int n, k;
    vector<int> sums;
    vector<vector<int>> memo;
    vector<int> indexes;

    int dp(int idx, int rem) {
        if (rem == 0)
            return 0;
        if (idx >= sums.size())
            return rem > 0 ? numeric_limits<int>::min() : 0;
        if (memo[idx][rem] != -1)
            return memo[idx][rem];
        int with_current = sums[idx] + dp(idx + k, rem - 1);
        int skip_current = dp(idx + 1, rem);
        memo[idx][rem] = max(with_current, skip_current);
        return memo[idx][rem];
    }

    void dfs(int idx, int rem) {
        if (rem == 0)
            return;
        if (idx >= sums.size())
            return;
        int with_current = sums[idx] + dp(idx + k, rem - 1);
        int skip_current = dp(idx + 1, rem);
        if (with_current >= skip_current) {
            indexes.emplace_back(idx);
            dfs(idx + k, rem - 1);
        }
        else
            dfs(idx + 1, rem);
    }
};
