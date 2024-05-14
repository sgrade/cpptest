// 1219. Path with Maximum Gold
// https://leetcode.com/problems/path-with-maximum-gold/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0)
                    continue;
                ans = max (ans, dfs(row, col, grid));
            }
        }
        return ans;
    }
private:
    int rows, cols;
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int dfs (int row, int col, vector<vector<int>>& grid) {
        int current_cell = grid[row][col];
        grid[row][col] = 0;
        int current_ans = 0;
        for (const auto& [r_diff, c_diff]: directions) {
            int new_row = row + r_diff;
            int new_col = col + c_diff;
            if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols ||
                grid[new_row][new_col] == 0)
                continue;
            current_ans = max(current_ans, dfs(new_row, new_col, grid));
        }
        grid[row][col] = current_cell;
        return current_ans + current_cell;
    }
};
