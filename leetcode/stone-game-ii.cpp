// 1140. Stone Game II
// https://leetcode.com/problems/stone-game-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Memoization
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));
        return f(0, 0, 1, piles, dp);
    }

private:
    int n;
    int f(int p, int i, int m, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (i == n)
            return 0;
        if (dp[p][i][m] != -1)
            return dp[p][i][m];
        int ans = p == 1 ? 1e7 : -1;
        int s = 0;
        for (int x = 1; x <= min(2 * m, n - i); ++x) {
            s += piles[i + x - 1];
            if (p == 0)
                ans = max(ans, s + f(1, i + x, max(m, x), piles, dp));
            else
                ans = min(ans, f(0, i + x, max(m, x), piles, dp));
        }
        return dp[p][i][m] = ans;
    }
};
