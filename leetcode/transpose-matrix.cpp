// 867. Transpose Matrix
// https://leetcode.com/problems/transpose-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                ans[col][row] = matrix[row][col];
            }
        }
        return ans;
    }
};
