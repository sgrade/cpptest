// 54. Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int min_row = 0, max_row = matrix.size() - 1;
        int min_col = 0, max_col = matrix[0].size() - 1;
        while (min_row <= max_row && min_col <= max_col) {
            for (int j = min_col; j <= max_col; ++j) {
                ans.emplace_back(matrix[min_row][j]);
            }
            ++min_row;
            for (int i = min_row; i <= max_row; ++i) {
                ans.emplace_back(matrix[i][max_col]);
            }
            --max_col;
            if (min_row <= max_row) {
                for (int j = max_col; j >= min_col; --j) {
                    ans.emplace_back(matrix[max_row][j]);
                }
            }
            --max_row;
            if (min_col <= max_col) {
                for (int i = max_row ; i >= min_row; --i) {
                    ans.emplace_back(matrix[i][min_col]);
                }
            }
            ++min_col;
        }
        return ans;
    }
};
