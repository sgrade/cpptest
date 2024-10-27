// 1277. Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Bottom-up Approach
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int rows = matrix.size(), cols = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 0)
                    continue;
                dp[row + 1][col + 1] = 1 + min ({
                    dp[row][col],
                    dp[row][col + 1],
                    dp[row + 1][col]
                });
                ans += dp[row + 1][col + 1];
            }
        }
        return ans;
    }
};
