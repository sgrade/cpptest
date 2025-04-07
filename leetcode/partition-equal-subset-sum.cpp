// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Top Down Dynamic Programming - Memoization
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % 2 != 0)
                return false;

            int n = nums.size();
            memo.resize(n + 1, vector<optional<bool>>(sum / 2 + 1));
            return dfs(nums, n - 1, sum / 2);
        }

    private:
        vector<vector<optional<bool>>> memo;

        bool dfs(vector<int>& nums, int n, int subset_sum) {
            if (subset_sum == 0)
                return true;
            if (n == 0 || subset_sum < 0)
                return false;
            if (memo[n][subset_sum] != nullopt)
                return (memo[n][subset_sum] == true);

            bool current_ans = dfs(nums, n - 1, subset_sum - nums[n - 1]) || dfs(nums, n - 1, subset_sum);
            memo[n][subset_sum] = current_ans;
            return current_ans;
        }
    };
