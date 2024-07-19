// 1380. Lucky Numbers in a Matrix
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // Based on Editorial's Approach 2: Greedy
        int rows = matrix.size(), cols = matrix[0].size();
        int ans;
        int max_of_row_mins = numeric_limits<int>::min(), col_of_max_of_row_mins = -1;
        for (int row = 0; row < rows; ++row) {
            int current_row_min = numeric_limits<int>::max(), col_of_current_row_min = -1;
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] < current_row_min) {
                    current_row_min = matrix[row][col];
                    col_of_current_row_min = col;
                }
            }
            if (current_row_min > max_of_row_mins) {
                max_of_row_mins = current_row_min;
                col_of_max_of_row_mins = col_of_current_row_min;
            }
        }

        for (int row = 0; row < rows; ++row) {
            if (matrix[row][col_of_max_of_row_mins] > max_of_row_mins)
                return {};
        }

        return {max_of_row_mins};
    }
};
