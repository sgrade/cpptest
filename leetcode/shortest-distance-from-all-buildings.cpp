// 317. Shortest Distance from All Buildings
// https://leetcode.com/problems/shortest-distance-from-all-buildings/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: BFS from Empty Land to All Houses
class Solution {
    public:
        int shortestDistance(vector<vector<int>>& grid) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            rows = grid.size(), cols = grid[0].size();
            int ans = numeric_limits<int>::max();

            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if (grid[row][col] == 1)
                        ++total_houses;
                }
            }

            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if (grid[row][col] == 0)
                        ans = min(ans, bfs(grid, row, col));
                }
            }

            if (ans == numeric_limits<int>::max())
                return -1;
            return ans;
        }

    private:
        int rows, cols, total_houses = 0;
        vector<pair<int, int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int bfs (vector<vector<int>>& grid, int start_row, int start_col) {
            int sum = 0, houses = 0;
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(rows, vector<bool>(cols));
            q.emplace(start_row, start_col);
            visited[start_row][start_col] = true;

            int steps = 0;
            while (!q.empty() && houses < total_houses) {
                for (int i = q.size(); i > 0; --i) {
                    auto [row, col] = q.front();
                    q.pop();

                    if (grid[row][col] == 1) {
                        sum += steps;
                        ++houses;
                        continue;
                    }

                    for (const auto& [r_diff, c_diff]: directions) {
                        int r = row + r_diff, c = col + c_diff;
                        if (r >= 0 && c >= 0 && r < rows && c < cols && !visited[r][c] && grid[r][c] != 2) {
                            visited[r][c] = true;
                            q.emplace(r, c);
                        }
                    }
                }
                ++steps;
            }

            // If we cannot reach all houses, then any visited cell cannot reach all houses
            // Setting them to 2 to avoid rechecking
            if (houses != total_houses) {
                for (int row = 0; row < rows; ++row) {
                    for (int col = 0; col < cols; ++col) {
                        if (grid[row][col] == 0 && visited[row][col])
                            grid[row][col] = 2;
                    }
                }
                return numeric_limits<int>::max();
            }

            return sum;
        }
    };
