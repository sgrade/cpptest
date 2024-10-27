// 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Top-Down Dynamic Programming
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = matrix.size(), cols = matrix[0].size();
        dp.resize(rows, vector<int>(cols, -1));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col)
                ans += Get(row, col, matrix);
        }
        return ans;
    }
private:
    int ans = 0, rows, cols;
    vector<vector<int>> dp;
    int Get (int row, int col, const vector<vector<int>>& matrix) {
        if (row >= rows || col >= cols || matrix[row][col] == 0)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int right = Get (row, col + 1, matrix);
        int below = Get (row + 1, col, matrix);
        int diag = Get (row + 1, col + 1, matrix);
        return dp[row][col] = 1 + min({right, below, diag});
    }
};
