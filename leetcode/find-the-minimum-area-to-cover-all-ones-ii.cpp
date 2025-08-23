// 3197. Find the Minimum Area to Cover All Ones II
// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


// Based on Editorial's Approach: Enumerate
class Solution {
public:
    int minimumSum(const vector<vector<int>>& grid) {
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

    int divideAndCalculate(const vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = rows * cols;
        for (int r = 0; r < rows - 1; ++r) {
            for (int c = 0; c < cols - 1; ++c) {
                int a = getMinSum(grid, 0, r, 0, cols - 1);
                int b = getMinSum(grid, r + 1, rows - 1, 0, c);
                int c1 = getMinSum(grid, r + 1, rows - 1, c + 1, cols - 1);
                if (a != std::numeric_limits<int>::max() && b != std::numeric_limits<int>::max() && c1 != std::numeric_limits<int>::max()) {
                    ans = min(ans, a + b + c1);
                }
                int a2 = getMinSum(grid, 0, r, 0, c);
                int b2 = getMinSum(grid, 0, r, c + 1, cols - 1);
                int c2 = getMinSum(grid, r + 1, rows - 1, 0, cols - 1);
                if (a2 != std::numeric_limits<int>::max() && b2 != std::numeric_limits<int>::max() && c2 != std::numeric_limits<int>::max()) {
                    ans = min(ans, a2 + b2 + c2);
                }
            }
        }
        for (int r = 0; r < rows - 2; ++r) {
            for (int c = r + 1; c < rows - 1; ++c) {
                int a = getMinSum(grid, 0, r, 0, cols - 1);
                int b = getMinSum(grid, r + 1, c, 0, cols - 1);
                int c1 = getMinSum(grid, c + 1, rows - 1, 0, cols - 1);
                if (a != std::numeric_limits<int>::max() && b != std::numeric_limits<int>::max() && c1 != std::numeric_limits<int>::max()) {
                    ans = min(ans, a + b + c1);
                }
            }
        }
        return ans;
    }

    int getMinSum(const vector<vector<int>>& grid, int up, int down, int left, int right) {
        int rows = grid.size(), cols = grid[0].size();
        int min_r = rows, max_r = -1;
        int min_c = cols, max_c = -1;
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
        if (max_r == -1) return std::numeric_limits<int>::max();
        return (max_r - min_r + 1) * (max_c - min_c + 1);
    }
};
