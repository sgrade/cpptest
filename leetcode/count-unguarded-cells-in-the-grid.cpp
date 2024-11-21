// 2257. Count Unguarded Cells in the Grid
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Iterative Simulation
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = m, cols = n;
        grid.resize(m, vector<int>(n, UNGUARDED));
        for (const auto& guard: guards)
            grid[guard[0]][guard[1]] = GUARD;
        for (const auto& wall: walls)
            grid[wall[0]][wall[1]] = WALL;
        for (const auto& guard: guards)
            setGuarded(guard[0], guard[1]);

        int ans = 0;
        for (const auto& row: grid) {
            for (const auto& cell: row) {
                if (cell == UNGUARDED)
                    ++ans;
            }
        }
        return ans;
    }

private:
    int rows, cols;
    const int UNGUARDED = 0, GUARDED = 1, GUARD = 2, WALL = 3;
    vector<vector<int>> grid;
    void setGuarded(int row, int col) {
        for (int r = row - 1; r >= 0; --r) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD)
                break;
            grid[r][col] = GUARDED;
        }
        for (int r = row + 1; r < rows; ++r) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD)
                break;
            grid[r][col] = GUARDED;
        }
        for (int c = col - 1; c >= 0; --c) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD)
                break;
            grid[row][c] = GUARDED;
        }
        for (int c = col + 1; c < cols; ++c) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD)
                break;
            grid[row][c] = GUARDED;
        }
    }
};
