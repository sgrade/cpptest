// 566. Reshape the Matrix
// https://leetcode.com/problems/reshape-the-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size(), cols = mat[0].size();
        if (r * c != rows * cols)
            return mat;
        
        vector<vector<int>> ans(r, vector<int>(c));
        int i = 0, j = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                ans[i][j++] = mat[row][col];
                if (j == c) {
                    ++i;
                    j = 0;
                }
            }
        }
        return ans;
    }
};
