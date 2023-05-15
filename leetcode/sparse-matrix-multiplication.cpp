// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Yale Format
class SparseMatrix {
public:
    int rows = 0, cols = 0;
    vector<int> values, col_index, row_index;

    // CSR - Compressed Sparse Row
    SparseMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        row_index.emplace_back(0);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols ; ++col) {
                if (matrix[row][col]) {
                    values.emplace_back(matrix[row][col]);
                    col_index.emplace_back(col);
                }
            }
            row_index.emplace_back(values.size());
        }
    }

    // CSC - Compressed Sparse Column
    SparseMatrix(vector<vector<int>>& matrix, bool col_wise) {
        rows = matrix.size();
        cols = matrix[0].size();
        col_index.emplace_back(0);
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (matrix[row][col]) {
                    values.emplace_back(matrix[row][col]);
                    row_index.emplace_back(row);
                }
            }
            col_index.emplace_back(values.size());
        }
    }
};


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int rows = mat1.size(), cols = mat2[0].size();
        SparseMatrix a(mat1);
        SparseMatrix b(mat2, true);
        vector<vector<int>> ans(rows, vector<int>(cols));
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int mat1_row_start = a.row_index[row];
                int mat1_row_end = a.row_index[row + 1];
                int mat2_col_start = b.col_index[col];
                int mat2_col_end = b.col_index[col + 1];
                while (mat1_row_start < mat1_row_end && mat2_col_start < mat2_col_end) {
                    if (a.col_index[mat1_row_start] < b.row_index[mat2_col_start])
                        ++mat1_row_start;
                    else if (a.col_index[mat1_row_start] > b.row_index[mat2_col_start])
                        ++mat2_col_start;
                    else {
                        ans[row][col] += a.values[mat1_row_start] * b.values[mat2_col_start];
                        ++mat1_row_start;
                        ++mat2_col_start;
                    }
                }
            }
        }
        
        return ans;
    }
};
