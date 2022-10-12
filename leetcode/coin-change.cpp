// 322. Coin Change
// https://leetcode.com/problems/coin-change/

// Based on Leetcode's Approach 3 (Dynamic programming - Bottom up)

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int ans = 0;
    int coinChange(vector<int>& coins, int amount) {
        int mx = amount + 1;
        vector<int> dp(amount + 1, mx);
        dp[0] = 0;
        for (int sm = 1; sm <= amount; ++sm) {
            for (const int &denom: coins) {
                if (denom <= sm) {
                    dp[sm] = min(dp[sm], dp[sm - denom] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
