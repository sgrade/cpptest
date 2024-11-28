// 2290. Minimum Obstacle Removal to Reach Corner
// https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dijkstra's Algorithm
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        min_obstacles.resize(rows, vector<int>(cols, INT_MAX));
        min_obstacles[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.emplace(vector<int>{min_obstacles[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0], row = current[1], col = current[2];
            if (row == rows - 1 && col == cols - 1)
                return obstacles;
            for (vector<int>& d: directions) {
                int r = row + d[0], c = col + d[1];
                if (isValid(r, c)) {
                    int new_obstacles = obstacles + grid[r][c];
                    if (new_obstacles < min_obstacles[r][c]) {
                        min_obstacles[r][c] = new_obstacles;
                        pq.emplace(vector<int>{new_obstacles, r, c});
                    }
                }
            }
        }
        return min_obstacles[rows - 1][cols - 1];
    }

private:
    int rows, cols;
    vector<vector<int>> min_obstacles;
    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    bool isValid (int r, int c) {
        return r >= 0 && c >= 0 && r < rows && c < cols;
    }
};
