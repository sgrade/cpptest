// 1727. Largest Submatrix With Rearrangements
// https://leetcode.com/problems/largest-submatrix-with-rearrangements/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: No Sort
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int rows = matrix.size(), cols = matrix[0].size();
        vector<pair<int, int>> prev_heights;
        int ans = 0;
        for (int row = 0; row < rows; ++row) {
            vector<pair<int, int>> heights;
            vector<bool> seen(cols);
            for (auto& [height, col]: prev_heights) {
                if (matrix[row][col] == 1) {
                    heights.emplace_back(height + 1, col);
                    seen[col] = true;
                }
            }
            for (int col = 0; col < cols; ++col) {
                if (seen[col] == false && matrix[row][col] == 1)
                    heights.emplace_back(1, col);
            }
            for (int i = 0; i < heights.size(); ++i)
                ans = max(ans, heights[i].first * (i + 1));
            prev_heights = heights;
        }
        return ans;
    }
};
