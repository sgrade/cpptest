// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

#include <bits/stdc++.h>

using namespace std;


// Based on sample 0 ms solution
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows = m, cols = n;
        vector dp(m + 1, vector(n + 1, vector<int>(maxMove + 1, -1)));
        return getNumOfPaths (startRow, startColumn, maxMove, dp);
    }
private:
    int rows, cols;
    int MOD = 1e9 + 7;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int getNumOfPaths (int row, int col, int moves, vector<vector<vector<int>>>& dp) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) 
            return 1;
        if (moves == 0)
            return 0;
        if (dp[row][col][moves] != -1)
            return dp[row][col][moves];
        
        int ans = 0;
        for (const auto& [row_diff, col_diff]: directions)
            ans = (ans + getNumOfPaths(row + row_diff, col + col_diff, moves - 1, dp) % MOD) % MOD;
        return dp[row][col][moves] = ans;
    }
};
