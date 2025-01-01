// 3402. Minimum Operations to Make Columns Strictly Increasing
// https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        for (int col = 0; col < grid[0].size(); ++col) {
            for (int row = 1; row < grid.size(); ++row) {
                if (grid[row][col] > grid[row - 1][col])
                    continue;
                int diff = grid[row - 1][col] - grid[row][col] + 1;
                ans += diff;
                grid[row][col] += diff;
            }
        }
        return ans;
    }
};
