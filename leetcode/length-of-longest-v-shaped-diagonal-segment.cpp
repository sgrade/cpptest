// 3459. Length of Longest V-Shaped Diagonal Segment
// https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::pair;


// Based on Editorial's Length of Longest V-Shaped Diagonal Segment
class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        memo.assign(rows, vector<vector<vector<int>>>(cols, vector<vector<int>>(4, vector<int>(2, -1))));;
        int ans = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        ans = max(ans, dfs(r, c, d, true, 2, grid) + 1);
                    }
                }
            }
        }
        return ans;
    }
private:
    int rows, cols;
    vector<vector<vector<vector<int>>>> memo;
    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dfs (int row, int col, int d, bool turn, int target, vector<vector<int>>& grid) {
        int r = row + directions[d].first, c = col + directions[d].second;
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != target) {
            return 0;
        }
        if (memo[r][c][d][turn] != -1) {
            return memo[r][c][d][turn];
        }

        int max_len = dfs(r, c, d, turn, 2 - target, grid);
        if (turn) {
            max_len = max(max_len, dfs(r, c, (d + 1) % 4, false, 2 - target, grid));
        }
        memo[r][c][d][turn] = max_len + 1;
        return max_len + 1;
    }
};
