// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memo.resize(n, vector<int>(amount + 1, -1));
        return NumberOfWays(0, amount, coins);
    }

private:
    int n;
    vector<vector<int>> memo;

    int NumberOfWays(int i, int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;
        if (i == n)
            return 0;
        if (memo[i][amount] != -1)
            return memo[i][amount];
        if (coins[i] > amount)
            return memo[i][amount] = NumberOfWays(i + 1, amount, coins);
        
        memo[i][amount] = NumberOfWays(i, amount - coins[i], coins) + NumberOfWays(i + 1, amount, coins);
        return memo[i][amount];
    }
};
