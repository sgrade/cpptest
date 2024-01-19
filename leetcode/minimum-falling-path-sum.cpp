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
                int left = col == 0 ? INT_MAX : matrix[row - 1][col - 1];
                int mid = matrix[row - 1][col];
                int right = col == cols - 1 ? INT_MAX : matrix[row - 1][col + 1];
                matrix[row][col] += min({left, mid, right});
            }
        }
        return *min_element(matrix[rows - 1].begin(), matrix[rows - 1].end());
    }
};
