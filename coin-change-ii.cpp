// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-Up Dynamic Programming
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // i - current coin, j - amount to get
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for (vector<int>& num_of_ways: dp)
            num_of_ways[0] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] > j)
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
            }
        }

        return dp[0][amount];
    }
};
