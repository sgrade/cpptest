// 3363. Find the Maximum Number of Fruits Collected
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }
        ans += traverse(fruits, n);

        // Flip along main diagonal
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < row; ++col) {
                swap(fruits[row][col], fruits[col][row]);
            }
        }

        ans += traverse(fruits, n);
        return ans;
    }

private:
    int traverse(const vector<vector<int>>& fruits, int n) {
        vector<int> dp(n, numeric_limits<int>::min());
        dp[n - 1] = fruits[0][n - 1];
        for (int row = 1; row < n - 1; ++row) {
            vector<int> new_dp(n, numeric_limits<int>::min());
            int start_col = max(n - 1 - row, row + 1);
            for (int col = start_col; col < n; ++col) {
                int prev_best = dp[col];
                if (col - 1 >= 0) {
                    prev_best = max(prev_best, dp[col - 1]);
                }
                if (col + 1 < n) {
                    prev_best = max(prev_best, dp[col + 1]);
                }
                if (prev_best != numeric_limits<int>::min()) {
                    new_dp[col] = prev_best + fruits[row][col];
                }
            }
            dp.swap(new_dp);
        }
        return dp[n - 1];
    }
};
