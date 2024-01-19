// 931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int row = 1; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int x = matrix[row - 1][col];
                if (col > 0)
                    x = min(x, matrix[row - 1][col - 1]);
                if (col < cols - 1)
                    x = min(x, matrix[row - 1][col + 1]);
                matrix[row][col] += x;
            }
        }
        return *min_element(matrix[rows - 1].begin(), matrix[rows - 1].end());
    }
};
