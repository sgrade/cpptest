// 361. Bomb Enemy
// https://leetcode.com/problems/bomb-enemy/

#include <bits/stdc++.h>

using namespace std;


// Slower than bomb-enemy.cpp
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        
        int ans = 0;
        
        vector<vector<pair<int, int>>> dp(rows + 1, vector<pair<int, int>>(cols + 1));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 'W') {
                    dp[row + 1][col + 1].first = 0;
                    dp[row + 1][col + 1].second = 0;
                    continue;
                }
                int cur = grid[row][col] == 'E';
                dp[row + 1][col + 1].first = dp[row][col + 1].first + cur;
                dp[row + 1][col + 1].second = dp[row + 1][col].second + cur;
            }
        }

        for (int row = dp.size() - 1; row > 0; --row) {
            for (int col = dp[0].size() - 1; col > 0; --col) {
                if (grid[row - 1][col - 1] == 'W')
                    continue;
                if (row + 1 < dp.size())
                    dp[row][col].first = max(dp[row][col].first, dp[row + 1][col].first);
                if (col + 1 < dp[0].size())
                    dp[row][col].second = max(dp[row][col].second, dp[row][col + 1].second);
            }
        }

        for (int row = 1; row <= rows; ++row) {
            for (int col = 1; col <= cols; ++col) {
                if (grid[row - 1][col - 1] == '0')
                    ans = max(ans, dp[row][col].first + dp[row][col].second);
            }
        }

        return ans;
    }
};
