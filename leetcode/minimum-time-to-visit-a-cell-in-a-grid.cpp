// 2577. Minimum Time to Visit a Cell In a Grid
// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Modified Dijkstra's Algorithm
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        rows = grid.size(), cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            int time, row, col;
            tie(time, row, col) = pq.top();
            pq.pop();
            if (row == rows - 1 && col == cols - 1)
                return time;
            if (visited[row][col])
                continue;
            visited[row][col] = true;
            for (const auto& [r_diff, c_diff]: directions) {
                int r = row + r_diff, c = col + c_diff;
                if (!isValid(r, c))
                    continue;
                int wait_time = (grid[r][c] - time) % 2 == 0 ? 1 : 0;
                int next_time = max(grid[r][c] + wait_time, time + 1);
                pq.emplace(next_time, r, c);
            }
        }
        return -1;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector<vector<bool>> visited;
    bool isValid(int& r, int& c) {
        return r >= 0 && c >= 0 && r < rows && c < cols;
    }
};
