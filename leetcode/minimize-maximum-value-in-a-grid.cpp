// 2371. Minimize Maximum Value in a Grid
// https://leetcode.com/problems/minimize-maximum-value-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Sorting
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = grid.size(), cols = grid[0].size();
        vector<tuple<int, int, int>> nums;
        vector<int> r(rows, 1), c(cols, 1);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                nums.emplace_back(grid[i][j], i, j);
        }
        sort(nums.begin(), nums.end());

        for (const auto& tup: nums) {
            int val, row, col;
            tie(val, row, col) = tup;
            val = max(r[row], c[col]);
            grid[row][col] = val;
            r[row] = c[col] = val + 1;
        }
        return grid;
    }
};
