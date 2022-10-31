// 64. Minimum Path Sum
// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int col = 1; col < cols; ++col) {
            grid[0][col] = grid[0][col - 1] + grid[0][col];
        }
        for (int row = 1; row < rows; ++row) {
            grid[row][0] = grid[row - 1][0] + grid[row][0];
        }
        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                grid[row][col] = grid[row][col] + min(grid[row-1][col], grid[row][col - 1]);
            }
        }
        return grid[rows - 1][cols - 1];
    }
};
