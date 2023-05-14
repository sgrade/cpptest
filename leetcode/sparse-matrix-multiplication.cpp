// 311. Sparse Matrix Multiplication
// https://leetcode.com/problems/sparse-matrix-multiplication/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int kk = 0; kk < k; ++kk) {
                    ans[i][j] += mat1[i][kk] * mat2[kk][j];
                }
            }
        }
        return ans;
    }
};
