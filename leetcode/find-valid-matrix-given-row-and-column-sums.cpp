// 1605. Find Valid Matrix Given Row and Column Sums
// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Greedy
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int rows = rowSum.size(), cols = colSum.size();
        vector<int> current_row_sum(rows), current_col_sum(cols);
        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                ans[row][col] = min(rowSum[row] - current_row_sum[row], colSum[col] - current_col_sum[col]);
                current_row_sum[row] += ans[row][col];
                current_col_sum[col] += ans[row][col];
            }
        }
        return ans;
    }
};
