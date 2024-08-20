// 1140. Stone Game II
// https://leetcode.com/problems/stone-game-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Dynamic Programming (Tabulation)
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> suffix_sum(n + 1);
        for (int i = n - 1; i >= 0; --i)
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        for (int i = 0; i <= n; ++i)
            dp[i][n] = suffix_sum[i];
        for (int i = n - 1; i >= 0; --i) {
            for (int current_max = n - 1; current_max >= 1; --current_max) {
                for (int x = 1; x <= 2 * current_max && i + x <= n; ++x) {
                    dp[i][current_max] = max (
                        dp[i][current_max], 
                        suffix_sum[i] - dp[i + x][max(current_max, x)]);
                }
            }
        }
        return dp[0][1];
    }
};
