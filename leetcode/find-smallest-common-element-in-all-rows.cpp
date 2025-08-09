// 1198. Find Smallest Common Element in All Rows
// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Row Positions
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int mx = 0, cnt = 0;
        vector<int> col_in(rows);
        while (true) {
            for (int row = 0; row < rows; ++row) {
                while (col_in[row] < cols && mat[row][col_in[row]] < mx) {
                    ++col_in[row];
                }
                if (col_in[row] >= cols) {
                    return -1;
                }
                if (mx != mat[row][col_in[row]]) {
                    cnt = 1;
                    mx = mat[row][col_in[row]];
                } else if (++cnt == rows) {
                    return mx;
                }
            }
        }
        return -1;
    }
};
