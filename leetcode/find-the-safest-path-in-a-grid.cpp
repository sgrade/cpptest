// 2812. Find the Safest Path in a Grid
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


// Used Dijkstra-like algorithm to find the shortest path from the source to the destination.
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
            return 0;

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    grid[row][col] = 500;
                    q.emplace(row, col);
                }
                else
                    grid[row][col] = 410;
            }
        }

        int moves = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                const auto [row, col] = q.front();
                q.pop();
                moves = grid[row][col] == 500 ? 0 : grid[row][col];
                for (const auto& [diff_r, diff_c]: directions) {
                    int new_row = row + diff_r, new_col = col + diff_c;
                    if (IsValid(new_row, new_col) && grid[new_row][new_col] == 410) {
                        grid[new_row][new_col] = moves + 1;
                        q.emplace(new_row, new_col);
                    }
                }
            }
        }

        int min_distance = 500;
        // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.emplace(grid[0][0], pair<int, int>(0, 0));
        grid[0][0] = 500;
        while (!pq.empty()) {
            const auto [current_distance, coordinates] = pq.top();
            pq.pop();
            const auto& [row, col] = coordinates;
            min_distance = min(min_distance, current_distance);
            if (row == rows - 1 && col == cols - 1)
                return min_distance;
            for (const auto& [diff_r, diff_c]: directions) {
                int new_row = row + diff_r, new_col = col + diff_c;
                if (!IsValid(new_row, new_col) || grid[new_row][new_col] == 500)
                    continue;
                pq.emplace(grid[new_row][new_col], pair<int, int>(new_row, new_col));
                // Mark visited
                grid[new_row][new_col] = 500;
            }
        }
        return 0;
    }

private:
    int rows, cols;
    // Down, right, up, left
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool IsValid (int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            return false;
        return true;
    }
};
