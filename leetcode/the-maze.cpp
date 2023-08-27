// 490. The Maze
// https://leetcode.com/problems/the-maze/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        rows = maze.size(), cols = maze[0].size();
        dst_row = destination[0];
        dst_col = destination[1];
        // for each cell: not visited = -1, left = 0, right = 1, up = 2, down = 3
        vector<vector<int>> tried(rows, vector<int>(cols, -1));

        queue<pair<int, int>> q;
        q.emplace(start[0], start[1]);
        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            if (row == dst_row && col == dst_col) 
                return true;
            while (++tried[row][col] < 4) {
                int next_row = row, next_col = col;
                int d = tried[row][col];
                int row_diff = directions[d].first, col_diff = directions[d].second;
                if (row_diff != 0) {
                    while (next_row + row_diff >= 0 && next_row + row_diff < rows && maze[next_row + row_diff][col] == 0)
                        next_row += row_diff;
                    if (next_row != row)
                        q.emplace(next_row, col);
                }
                else {
                    while (next_col + col_diff >= 0 && next_col + col_diff < cols && maze[row][next_col + col_diff] == 0)
                        next_col += col_diff;
                    if (next_col != col)
                        q.emplace(row, next_col);
                }
            }
        }
        return false;
    }

private:
    int rows, cols;
    int dst_row, dst_col;
    vector<pair<int, int>> directions {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
};
