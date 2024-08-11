// 1568. Minimum Number of Days to Disconnect Island
// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Tarjan's Algorithm
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = grid.size(), cols = grid[0].size();
        ArticulationPointInfo ap_info (false, 0);
        int land_cells = 0, island_count = 0;
        vector<vector<int>> discovery_time (rows, vector<int>(cols, -1));
        vector<vector<int>> lowest_reachable (rows, vector<int>(cols, -1));
        vector<vector<int>> parent_cell (rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++land_cells;
                    if (discovery_time[i][j] == -1) {
                        FindArticulationPoints (grid, i, j, discovery_time, lowest_reachable, parent_cell, ap_info);
                        ++island_count;
                    }
                }
            }
        }
        if (island_count == 0 || island_count >= 2)
            return 0;
        if (land_cells == 1)
            return 1;
        if (ap_info.has_articulation_point)
            return 1;
        return 2;
    }
private:
    int rows, cols;
    const vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    struct ArticulationPointInfo {
        bool has_articulation_point;
        int time;

        ArticulationPointInfo (bool has_articulation_point, int time) 
            : has_articulation_point (has_articulation_point), time (time) {}
    };
    bool IsValidLandCell (const vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols && grid[row][col] == 1;
    }
    void FindArticulationPoints (vector<vector<int>>& grid, int row, int col, 
        vector<vector<int>>& discovery_time,
        vector<vector<int>>& lowest_reachable,
        vector<vector<int>>& parent_cell,
        ArticulationPointInfo& ap_info) {
            discovery_time[row][col] = ap_info.time;
            ++ap_info.time;
            lowest_reachable[row][col] = discovery_time[row][col];
            int children = 0;

            for (const auto& direction: directions) {
                int new_row = row + direction[0];
                int new_col = col + direction[1];
                if (IsValidLandCell (grid, new_row, new_col)) {
                    if (discovery_time[new_row][new_col] == -1) {
                        ++children;
                        parent_cell[new_row][new_col] = row * cols + col;
                        FindArticulationPoints (grid, new_row, new_col, discovery_time, lowest_reachable, parent_cell, ap_info);
                        lowest_reachable[row][col] = min(lowest_reachable[row][col], lowest_reachable[new_row][new_col]);
                        if (lowest_reachable[new_row][new_col] >= discovery_time[row][col] && parent_cell[row][col] != -1) {
                            ap_info.has_articulation_point = true;
                        }
                    }
                    else if (new_row * cols + new_col != parent_cell[row][col]) {
                        lowest_reachable[row][col] = min(lowest_reachable[row][col], discovery_time[new_row][new_col]);
                }
            }
        }

        if (parent_cell[row][col] == -1 && children > 1)
            ap_info.has_articulation_point = true;
    }
};
