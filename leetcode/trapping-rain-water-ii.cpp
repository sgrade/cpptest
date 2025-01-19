// 407. Trapping Rain Water II
// https://leetcode.com/problems/trapping-rain-water-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: BFS + Priority Queue
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        rows = heightMap.size(), cols = heightMap[0].size();
        visited.resize(rows, vector<bool>(cols));

        priority_queue<Cell> pq;
        for (int r = 0; r < rows; ++r) {
            pq.emplace(heightMap[r][0], r, 0);
            pq.emplace(heightMap[r][cols - 1], r, cols - 1);
            visited[r][0] = visited[r][cols - 1] = true;
        }
        for (int c = 0; c < cols; ++c) {
            pq.emplace(heightMap[0][c], 0, c);
            pq.emplace(heightMap[rows - 1][c], rows - 1, c);
            visited[0][c] = visited[rows - 1][c] = true;
        }

        int ans = 0;
        while (!pq.empty()) {
            Cell current = pq.top();
            pq.pop();

            int row = current.r, col = current.c, cur_height = current.height;
            for (const auto& [r_diff, c_diff]: directions) {
                int r = row + r_diff, c = col + c_diff;
                if (!isValid(r, c) || visited[r][c])
                    continue;
                int neighbor_height = heightMap[r][c];
                if (neighbor_height < cur_height)
                    ans += cur_height - neighbor_height;
                pq.emplace(max(neighbor_height, cur_height), r, c);
                visited[r][c] = true;
            }
        }
        return ans;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };
    vector<vector<bool>> visited;

    class Cell {
    public:
        int height, r, c;
        Cell (int height, int row, int col) : height(height), r(row), c(col) {}
        bool operator < (const Cell& other) const {
            return height >= other.height;
        }
    };

    bool isValid(int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
};
