// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 3: Dynamic Programming
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        int ans = 0;
        for (int moves = 1; moves <= maxMove; ++moves) {
            vector<vector<int>> temp(m, vector<int>(n));
            for (int row = 0; row < m; ++row) {
                for (int col = 0; col < n; ++col) {
                    if (row == 0)
                        ans = (ans + dp[row][col]) % MOD;
                    if (row == m - 1)
                        ans = (ans + dp[row][col]) % MOD;
                    if (col == 0)
                        ans = (ans + dp[row][col]) % MOD;
                    if (col == n - 1)
                        ans = (ans + dp[row][col]) % MOD;
                    temp[row][col] = (
                        ((row > 0 ? dp[row - 1][col] : 0) + (row < m - 1 ? dp[row + 1][col] : 0)) % MOD + 
                        ((col > 0 ? dp[row][col - 1] : 0) + (col < n - 1 ? dp[row][col + 1] : 0)) % MOD
                    ) % MOD;
                }
            }
            dp = temp;
        }
        return ans;
    }
};
