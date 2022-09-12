// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> cols_with_zero;
        bool zero_in_row;
        for (int i = 0; i < rows; ++i) {
            zero_in_row = false;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    zero_in_row = true;
                    cols_with_zero.emplace_back(j);
                }
            }
            if (zero_in_row) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
                zero_in_row = false;
            }
        }
        for (int &col: cols_with_zero) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};
