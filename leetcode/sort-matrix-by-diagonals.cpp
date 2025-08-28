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
            int row = d < rows ? rows - d : 0;
            int col = d < rows ? 0 : d - rows;
            int n = std::min(rows - row, cols - col);
            vector<int> d_nums(n);
            for (int i = 0; i < n; ++i) {
                d_nums[i] = (grid[row + i][col + i]);
            }
            auto cmp = (d <= rows) ? [](int a, int b) { return a > b; } : [](int a, int b) { return a < b; };
            sort(d_nums.begin(), d_nums.end(), cmp);
            for (int i = 0; i < n; ++i) {
                grid[row + i][col + i] = d_nums[i];
            }
        }
        return grid;
    }
};
