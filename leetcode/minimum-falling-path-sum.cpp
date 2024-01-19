// 931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> cur = matrix[0];
        for (int row = 1; row < rows; ++row) {
            vector<int> prev = cur;
            for (int col = 0; col < cols; ++col) {
                int left = col == 0 ? INT_MAX : prev[col - 1];
                int mid = prev[col];
                int right = col == cols - 1 ? INT_MAX : prev[col + 1];
                cur[col] = min({left, mid, right}) + matrix[row][col];
            }
        }
        return *min_element(cur.begin(), cur.end());
    }
};
