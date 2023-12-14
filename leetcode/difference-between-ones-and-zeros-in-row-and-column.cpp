// 2482. Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ones_row(rows), ones_col(cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    ++ones_row[row];
                    ++ones_col[col];
                }
            }
        }
        int rows_cols = rows + cols;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                grid[row][col] = 2 * ones_row[row] + 2 * ones_col[col] - rows_cols;
            }
        }
        return grid;
    }
};
