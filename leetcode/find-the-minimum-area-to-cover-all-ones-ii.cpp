// 3197. Find the Minimum Area to Cover All Ones II
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


// Based on Editorial's Approach: Enumerate
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int original = divideAndCalculate(grid);
        vector<vector<int>> rotatedGrid = rotate(grid);
        int rotated = divideAndCalculate(rotatedGrid);
        return min(original, rotated);
    }

private:
    vector<vector<int>> rotate(const vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                rotated[cols - c - 1][r] = grid[r][c];
            }
        }
        return rotated;
    }

    int divideAndCalculate(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = rows * cols;
        for (int r = 0; r < rows - 1; ++r) {
            for (int c = 0; c < cols - 1; ++c) {
                ans = min(ans,
                    getMinSum(grid, 0, r, 0, cols - 1) + 
                    getMinSum(grid, r + 1, rows - 1, 0, c) +
                    getMinSum(grid, r + 1, rows - 1, c + 1, cols - 1)
                );
                ans = min(ans, 
                    getMinSum(grid, 0, r, 0, c) +
                    getMinSum(grid, 0, r, c + 1, cols - 1) +
                    getMinSum(grid, r + 1, rows - 1, 0, cols - 1)
                );
            }
        }
        for (int r = 0; r < rows - 2; ++r) {
            for (int c = r + 1; c < rows - 1; ++c) {
                ans = min(ans,
                    getMinSum(grid, 0, r, 0, cols - 1) +
                    getMinSum(grid, r + 1, c, 0, cols - 1) +
                    getMinSum(grid, c + 1, rows - 1, 0, cols - 1)
                );
            }
        }
        return ans;
    }

    int getMinSum(vector<vector<int>>& grid, int up, int down, int left, int right) {
        int rows = grid.size(), cols = grid[0].size();
        int min_r = rows, max_r = 0;
        int min_c = cols, max_c = 0;
        for (int r = up; r <= down; ++r) {
            for (int c = left; c <= right; ++c) {
                if (grid[r][c] == 1) {
                    min_r = min(min_r, r);
                    max_r = max(max_r, r);
                    min_c = min(min_c, c);
                    max_c = max(max_c, c);
                }
            }
        }
        return min_r <= max_r ? (max_r - min_r + 1) * (max_c - min_c + 1) : numeric_limits<int>::max() / 3;
    }
};
