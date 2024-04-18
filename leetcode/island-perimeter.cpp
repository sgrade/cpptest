// 463. Island Perimeter
// https://leetcode.com/problems/island-perimeter/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Better Counting
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    ans += 4;
                    if (row > 0 && grid[row - 1][col] == 1)
                        ans -= 2;
                    if (col > 0 && grid[row][col - 1] == 1)
                        ans -= 2;
                }
            }
        }
        return ans;
    }
};
