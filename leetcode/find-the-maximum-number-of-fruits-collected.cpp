// 3363. Find the Maximum Number of Fruits Collected
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Dynamic Programming
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size(), ans = 0;
        
        // From top left along main diagonal
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
        }

        // From top right
        ans += traverse(fruits);

        // Flip the fruits along main diagonal
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < row; ++col) {
                swap(fruits[row][col], fruits[col][row]);
            }
        }

        // From bot left, which became top right after the flip
        ans += traverse(fruits);
        return ans;
    }

private:
    int n, ans;

    // dp
    int traverse (vector<vector<int>>& fruits) {
        vector<int> prev(n, numeric_limits<int>::min()), cur(n, numeric_limits<int>::min());
        prev[n - 1] = fruits[0][n - 1];
        for (int row = 1; row < n - 1; ++row) {
            int start_col = max(n - 1 - row, row + 1);
            for (int col = start_col; col < n; ++col) {
                int prev_best = prev[col];
                if (col - 1 >= 0) {
                    prev_best = max(prev_best, prev[col - 1]);
                }
                if (col + 1 < n) {
                    prev_best = max(prev_best, prev[col + 1]);
                }
                cur[col] = prev_best + fruits[row][col];
            }
            swap(prev, cur);
        }
        return prev[n - 1];
    }
};
