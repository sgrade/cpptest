// 221. Maximal Square
// https://leetcode.com/problems/maximal-square/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach #3 (Better Dynamic Programming)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols + 1);
        int max_len = 0;
        int prev = 0, temp;
        for (int row = 1; row <= rows; ++row) {
            for (int col = 1; col <= cols; ++col) {
                temp = dp[col];
                if (matrix[row - 1][col - 1] == '1') {
                    dp[col] = min (min(dp[col - 1], prev), dp[col]) + 1;
                    max_len = max(dp[col], max_len);
                }
                else {
                    dp[col] = 0;
                }
                prev = temp;
            }
        }
        return max_len * max_len;
    }
};
