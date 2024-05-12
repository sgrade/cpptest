// 2373. Largest Local Values in a Matrix
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = grid.size(), cols = grid[0].size();
        int mx = 0;
        vector<vector<int>> ans(rows - 2, vector<int>(cols - 2, mx));
        for (int row = 0; row < rows - 2; ++row) {
            for (int col = 0; col < cols - 2; ++col) {
                int mx = 0;
                for (int r = row; r < min(rows, row + 3); ++r) {
                    for (int c = col; c < min(cols, col + 3); ++c) {
                        mx = max(mx, grid[r][c]);
                    }
                }
                ans[row][col] = mx;
            }
        }
        return ans;
    }
};
