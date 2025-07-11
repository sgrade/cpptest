// 3603. Minimum Cost Path with Alternating Directions II
// https://leetcode.com/problems/minimum-cost-path-with-alternating-directions-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = m, cols = n;
        memo.resize(rows, vector<long>(cols));
        memo[0][0] = (0 + 1) * (0 + 1);
        for (int col = 1; col < cols; ++col)
            memo[0][col] = memo[0][col - 1] + (col + 1) + waitCost[0][col];
        for (int row = 1; row < rows; ++row)
            memo[row][0] = memo[row - 1][0] + (row + 1) + waitCost[row][0];

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                int 
                enter = (row + 1) * (col + 1),
                wait = waitCost[row][col];
                memo[row][col] = min(memo[row][col - 1], memo[row - 1][col]) + enter + wait;
            }
        }
        return memo[rows - 1][cols - 1] - waitCost[rows - 1][cols - 1];
    }

private:
    int rows, cols;
    vector<vector<long>> memo;
};
