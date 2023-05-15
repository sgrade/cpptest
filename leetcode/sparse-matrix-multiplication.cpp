// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: List of Lists
// Optimizes space and, as a result, for sparse matrices, time. 
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int rows = mat1.size(), kk = mat1[0].size(), cols = mat2[0].size();
        vector<vector<pair<int, int>>> a = CompressMatrix(mat1);
        vector<vector<pair<int, int>>> b = CompressMatrix(mat2);
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (const auto& [a_el, a_col]: a[row]) {
                for (const auto& [b_el, b_col]: b[a_col]) {
                    ans[row][b_col] += a_el * b_el;
                } 
            }
        }
        return ans;
    }

private:
    vector<vector<pair<int, int>>> CompressMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<pair<int, int>>> compressed_matrix(rows);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != 0)
                    compressed_matrix[row].emplace_back(matrix[row][col], col);
            }
        }
        return compressed_matrix;
    }
};
