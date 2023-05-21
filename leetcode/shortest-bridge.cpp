// 934. Shortest Bridge
// https://leetcode.com/problems/shortest-bridge/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First-Search + Breadth-First-Search
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        bool found_island = false;
        for (int row = 0; !found_island && row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    dfs(grid, row, col);
                    found_island = true;
                    break;
                }
            }
        }

        int ans = 0;
        while (!bfs_q.empty()) {
            int cnt = bfs_q.size();
            while (cnt--) {
                auto &[row, col] = bfs_q.front();
                for (auto &[rr, cc] : directions) {
                    int r = row + rr, c = col + cc;
                    if (r < 0 || r == n || c < 0 || c == n)
                        continue;
                    if (grid[r][c] == 1)
                        return ans;
                    if (grid[r][c] == 0) {
                        bfs_q.emplace(r, c);
                        grid[r][c] = -1;
                    }
                }
                bfs_q.pop();
            }
            ++ans;
        }

        return ans;
    }

private:
    int n;
    queue<pair<int, int>> bfs_q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Marking all the cells in an island with 2
    // The cells in another island will stay 1
    void dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 2;
        bfs_q.emplace(row, col);
        for (auto &[rr, cc] : directions) {
            int r = row + rr, c = col + cc;
            if (r < 0 || r == n || c < 0 || c == n)
                continue;
            if (grid[r][c] == 1)
                dfs(grid, r, c);
        }
    }
};
