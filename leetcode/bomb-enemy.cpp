// 361. Bomb Enemy
// https://leetcode.com/problems/bomb-enemy/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Dynamic Programming
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        int row_hits = 0;
        vector<int> col_hits(cols);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                
                if (col == 0 || grid[row][col - 1] == 'W') {
                    row_hits = 0;
                    for (int c = col; c < cols; ++c) {
                        if (grid[row][c] == 'W') {
                            break;
                        }
                        else if (grid[row][c] == 'E') {
                            ++row_hits;
                        }
                    }
                }

                if (row == 0 || grid[row - 1][col] == 'W') {
                    col_hits[col] = 0;
                    for (int r = row; r < rows; ++r) {
                        if (grid[r][col] == 'W') {
                            break;
                        }
                        else if (grid[r][col] == 'E') {
                            col_hits[col] += 1;
                        }
                    }
                }

                if (grid[row][col] == '0') {
                    int current_ans = row_hits + col_hits[col];
                    ans = max(ans, current_ans);
                }
            }
        }

        return ans;
    }
};
