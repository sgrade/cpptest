// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int rows = mat1.size(), kk = mat1[0].size(), cols = mat2[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int k = 0; k < kk; ++k) {
                if (mat1[row][k] != 0) {
                    for (int col = 0; col < cols; ++col) {
                        ans[row][col] += mat1[row][k] * mat2[k][col];
                    }
                }
            }
        }
        return ans;
    }
};
