// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Dynamic Programming
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> dp = mat;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (dp[row][col] == 0)
                    continue;
                int min_neighbor = rows * cols;
                if (row > 0)
                    min_neighbor = min(min_neighbor, dp[row - 1][col]);
                if (col > 0)
                    min_neighbor = min(min_neighbor, dp[row][col - 1]);
                dp[row][col] = min_neighbor + 1;
            }
        }

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if (dp[row][col] == 0)
                    continue;
                int min_neighbor = rows * cols;
                if (row < rows - 1)
                    min_neighbor = min(min_neighbor, dp[row + 1][col]);
                if (col < cols - 1)
                    min_neighbor = min(min_neighbor, dp[row][col + 1]);
                dp[row][col] = min(dp[row][col], min_neighbor + 1);
            }
        }

        return dp;
    }

private:
    int rows, cols;
};
