// 1289. Minimum Falling Path Sum II
// https://leetcode.com/problems/freedom-trail/

#include <bits/stdc++.h>

using namespace std;


// Key idea is from Editorial's Approach 4: Space-Optimized Bottom-Up Dynamic Programming
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> prev_val(0, 0);
        pair<int, int> prev_idx(-1, -1);

        for (int row = 0; row < n; ++row) {
            pair<int, int> cur_val (20000, 20000);
            pair<int, int> cur_idx(-1, -1);

            for (int col = 0; col < n; ++col) {
                int x = grid[row][col];
                if (col != prev_idx.first)
                    x += prev_val.first;
                else {
                    x += prev_val.second;
                }

                if (x <= cur_val.first) {
                    cur_val.second = cur_val.first;
                    cur_idx.second = cur_idx.first;
                    cur_val.first = x;
                    cur_idx.first = col;
                }
                else if (x <= cur_val.second) {
                    cur_val.second = x;
                    cur_idx.second = col;
                }
            }

            prev_val = cur_val;
            prev_idx = cur_idx;
        }

        return prev_val.first;
    }
};
