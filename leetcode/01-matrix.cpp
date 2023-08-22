// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Breadth-First Search (BFS)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        queue<vector<int>> q;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 0) {
                    ans[row][col] = mat[row][col];
                    q.emplace(vector<int>{row, col, 0});
                    visited[row][col] = true;
                }
            }
        }

        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            int row = current[0], col = current[1], dist = current[2];
            for (auto& [row_diff, col_diff]: directions) {
                int next_row = row + row_diff, next_col = col + col_diff;
                if (next_row < 0 || next_row == rows || next_col < 0 || next_col == cols || visited[next_row][next_col])
                    continue;
                visited[next_row][next_col] = true;
                q.emplace(vector<int>{next_row, next_col, dist + 1});
                ans[next_row][next_col] = dist + 1;
            }
        }

        return ans;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
