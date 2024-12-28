// 494. Target Sum
// https://leetcode.com/problems/target-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Recursion with Memoization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->target = target;
        n = nums.size();
        total_sum = accumulate(nums.begin(), nums.end(), 0);
        memo.resize(n, vector<int>(2 * total_sum + 1, numeric_limits<int>::min()));
        return getWays(nums, 0, 0);
    }
private:
    int target, n, total_sum;
    vector<vector<int>> memo;
    int getWays(vector<int>& nums, int idx, int sum) {
        if (idx == n) {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        else {
            if (memo[idx][sum + total_sum] != numeric_limits<int>::min())
                return memo[idx][sum + total_sum];
            int add = getWays(nums, idx + 1, sum + nums[idx]);
            int substract = getWays(nums, idx + 1, sum - nums[idx]);
            memo[idx][sum + total_sum] = add + substract;
            return memo[idx][sum + total_sum];
        }
    }
};
