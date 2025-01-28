// 2658. Maximum Number of Fish in a Grid
// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols));
        int ans = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0 || visited[row][col])
                    continue;
                int current_ans = getFish(grid, row, col);
                ans = max(ans, current_ans);
            }
        }
        return ans;
    }

private:
    int rows, cols;
    vector<vector<bool>> visited;
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    int getFish(vector<vector<int>>& grid, int start_row, int start_col) {
        int current_ans = 0;
        queue<pair<int, int>> q;
        q.emplace(start_row, start_col);
        visited[start_row][start_col] = true;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            current_ans += grid[row][col];
            for (const auto& [r_diff, c_diff]: directions) {
                int r = row + r_diff, c = col + c_diff;
                if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0 || visited[r][c])
                    continue;
                q.emplace(r, c);
                visited[r][c] = true;
            }
        }
        return current_ans;
    }
};
