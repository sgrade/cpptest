// 1582. Special Positions in a Binary Matrix
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 2: Precompute the Number of Ones in each Row and Column
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int rows = mat.size(), cols = mat[0].size();
        vector<int> row_counter(rows), col_counter(cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 1) {
                    ++row_counter[row];
                    ++col_counter[col];
                }
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] == 1) {
                    if (row_counter[row] == 1 && col_counter[col] == 1)
                        ++ans;
                }
            }
        }

        return ans;
    }
};
