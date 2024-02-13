// 1463. Cherry Pickup II
// https://leetcode.com/problems/cherry-pickup-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #1: Dynamic Programming (Top Down)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        memo.resize(rows, vector<vector<int>> (cols, vector<int>(cols, -1)));
        return dp(0, 0, cols - 1, grid);
    }
private:
    int rows, cols;
    vector<vector<vector<int>>> memo;
    int dp(int row, int col1, int col2, vector<vector<int>>& grid) {
        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
            return 0;
        if (memo[row][col1][col2] != -1)
            return memo[row][col1][col2];
        int ans = 0;
        ans += grid[row][col1];
        if (col1 != col2)
            ans += grid[row][col2];
        if (row != rows - 1) {
            int mx = 0;
            for (int new_col1 = col1 - 1; new_col1 <= col1 + 1; ++new_col1)
                for (int new_col2 = col2 - 1; new_col2 <= col2 + 1; ++new_col2)
                    mx = max(mx, dp(row + 1, new_col1, new_col2, grid));
            ans += mx;
        }
        memo[row][col1][col2] = ans;
        return ans;
    }
};
