// 766. Toeplitz Matrix
// https://leetcode.com/problems/toeplitz-matrix/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row > 0 && col > 0 && matrix[row - 1][col - 1] != matrix[row][col])
                    return false;
            }
        }
        return true;
    }
};
