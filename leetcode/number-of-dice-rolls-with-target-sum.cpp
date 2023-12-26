// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        this->n = n;
        this->k = k;
        this->target = target;
        memo.resize(n + 1, vector<int>(target + 1, -1));
        return traverse(0, 0);
    }
private:
    const int MOD = 1e9 + 7;
    int n, k, target;
    vector<vector<int>> memo;
    int traverse(int idx, int cur_sum) {
        if (idx == n)
            return cur_sum == target;
        if (memo[idx][cur_sum] != -1)
            return memo[idx][cur_sum];
        int ways = 0;
        for (int i = 1; i <= min(k, target - cur_sum); ++i)
            ways = (ways + traverse(idx + 1, cur_sum + i)) % MOD;
        return memo[idx][cur_sum] = ways;
    }
};
