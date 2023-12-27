// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-Up Dynamic Programming
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1));
        memo[n][target] = 1;
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int cur_sum = 0; cur_sum <= target; ++cur_sum) {
                int ways = 0;
                for (int i = 1; i <= min(k, target - cur_sum); ++i)
                    ways = (ways + memo[idx + 1][cur_sum + i]) % MOD;
                memo[idx][cur_sum] = ways;
            }
        }
        return memo[0][0];
    }
private:
    const int MOD = 1e9 + 7;
};
