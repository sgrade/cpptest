// 3446. Sort Matrix by Diagonals
// https://leetcode.com/problems/sort-matrix-by-diagonals/

#include <vector>
#include <algorithm>
#include <functional>

using std::vector;
using std::sort;
using std::greater;


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int d = 1; d < rows + cols; ++d) {
            vector<int> d_nums;
            int row = d < rows ? rows - d : 0;
            int col = d < rows ? 0 : d - rows;
            int r = row, c = col;
            while (r < rows && c < cols) {
                d_nums.emplace_back(grid[r++][c++]);
            }
            if (d <= rows) {
                sort(d_nums.begin(), d_nums.end(), greater<int>());
            }
            else {
                sort(d_nums.begin(), d_nums.end());
            }
            r = row, c = col;
            int i = 0;
            while (i < d_nums.size()) {
                grid[r++][c++] = d_nums[i++];
            }
        }
        return grid;
    }
};
