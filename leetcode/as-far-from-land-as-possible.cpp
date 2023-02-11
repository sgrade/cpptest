// 1162. As Far from Land as Possible
// https://leetcode.com/problems/as-far-from-land-as-possible/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Dynamic-Programming
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        const int max_distance = rows + cols + 1;
        vector<vector<int>> dist(rows, vector<int>(cols, max_distance));

        // First pass: top and left
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) dist[i][j] = 0;
                else {
                    dist[i][j] = min(
                        dist[i][j], 
                        min(i > 0 ? dist[i - 1][j] + 1 : max_distance, 
                            j > 0 ? dist[i][j - 1] + 1: max_distance)
                    );
                }
            }
        }

        // Second pass: right and bottom
        int ans = numeric_limits<int>::min();
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (grid[i][j] == 1) dist[i][j] = 0;
                else {
                    dist[i][j] = min (
                        dist[i][j],
                        min(i < rows - 1 ? dist[i + 1][j] + 1 : max_distance, 
                            j < cols - 1 ? dist[i][j + 1] + 1 : max_distance)
                    );
                }
                ans = max(ans, dist[i][j]);
            }
        }

        return ans == 0 || ans == max_distance ? -1 : ans;
    }
};
