// 741. Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #2: Dynamic Programming (Top Down)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memo.resize(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dp(0, 0, 0, grid));
    }
private:
    int n;
    vector<vector<vector<int>>> memo;
    int dp(int r1, int c1, int c2, vector<vector<int>>& grid) {
        int r2 = r1 + c1 - c2;
        if (r1 == n || c1 == n || r2 == n || c2 == n || 
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        else if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];
        else if (memo[r1][c1][c2] != INT_MIN)
            return memo[r1][c1][c2];
        else {
            int ans = grid[r1][c1];
            if (c1 != c2)
                ans += grid[r2][c2];
            ans += max(
                max(dp(r1, c1 + 1, c2 + 1, grid), dp(r1 + 1, c1, c2 + 1, grid)),
                max(dp(r1, c1 + 1, c2, grid), dp(r1 + 1, c1, c2, grid))
            );
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
};
