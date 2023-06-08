// 1351. Count Negative Numbers in a Sorted Matrix
// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size(), cols = grid[0].size(), max_col = cols;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < max_col; ++col) {
                if (grid[row][col] < 0) {
                    ans += cols - col;
                    max_col = col + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
