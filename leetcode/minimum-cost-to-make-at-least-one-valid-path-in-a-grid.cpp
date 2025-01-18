// 1368. Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dynamic Programming
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        dp[0][0] = 0;

        while (true) {
            vector<vector<int>> prev = dp;

            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {

                    if (row > 0) {
                        dp[row][col] = min(dp[row][col], dp[row - 1][col] + (grid[row - 1][col] == 3 ? 0 : 1));
                    }

                    if (col > 0) {
                        dp[row][col] = min(dp[row][col], dp[row][col - 1] + (grid[row][col - 1] == 1 ? 0 : 1));
                    }
                }
            }

            for (int row = rows - 1; row >= 0; --row) {
                for (int col = cols - 1; col >= 0; --col) {

                    if (row < rows - 1) {
                        dp[row][col] = min(dp[row][col], dp[row + 1][col] + (grid[row + 1][col] == 4 ? 0 : 1));
                    }

                    if (col < cols - 1) {
                        dp[row][col] = min(dp[row][col], dp[row][col + 1] + (grid[row][col + 1] == 2 ? 0 : 1));
                    }
                }
            }

            if (prev == dp)
                break;
        }

        return dp[rows - 1][cols - 1];
    }
};
