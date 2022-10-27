// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x = 1;
        int len = n, current_len;
        int row = 0, col = 0;
        int i, j;
        while (x <= n * n) {
            for (j = col; j < col + len; ++j) {
                ans[row][j] = x;
                ++x;
            }
            col = --j;
            ++row;
            --len;
            if (len == 0) {
                break;
            }
            for (i = row; i < row + len; ++i) {
                ans[i][col] = x;
                ++x;
            }
            row = --i;
            --col;
            for (j = col; j > col - len; --j) {
                ans[row][j] = x;
                ++x;
            }
            col = ++j;
            --row;
            --len;
            for (i = row; i > row - len; --i) {
                ans[i][col] = x;
                ++x;
            }
            row = ++i;
            ++col;
        }
        return ans;
    }
};
