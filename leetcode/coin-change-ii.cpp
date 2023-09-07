// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Dynamic Programming with Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};
