// 120. Triangle
// https://leetcode.com/problems/triangle/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = triangle[0][0];
        int smallest_above;
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col < row + 1; ++col) {
                smallest_above = numeric_limits<int>::max();
                if (col > 0) {
                    smallest_above = triangle[row - 1][col - 1];
                }
                if (col < row) {
                    smallest_above = min(smallest_above, triangle[row - 1][col]);
                }
                triangle[row][col] += smallest_above;
            }
        }
        ans = *min_element(triangle[n-1].begin(), triangle[n-1].end());
        return ans;
    }
};
