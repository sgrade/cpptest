// 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: O(1) Space, Efficient Solution
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = matrix.size(), cols = matrix[0].size();
        bool first_col = false;
        for (int r = 0; r < rows; ++r) {
            if (matrix[r][0] == 0)
                first_col = true;
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for (int r = 1; r < rows; ++r) {
            for (int c = 1; c < cols; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                    matrix[r][c] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int c = 0; c < cols; ++c)
                matrix[0][c] = 0;
        }
        if (first_col) {
            for (int r = 0; r < rows; ++r)
                matrix[r][0] = 0;
        }
    }
};
