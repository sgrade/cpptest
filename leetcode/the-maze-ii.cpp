// 505. The Maze II
// https://leetcode.com/problems/the-maze-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #3 Using Dijkstra Algorithm
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        rows = maze.size(), cols = maze[0].size();
        dst_row = destination[0], dst_col = destination[1];
        distance.resize(rows, vector<int>(cols, numeric_limits<int>::max()));
        visited.resize(rows, vector<bool>(cols));
        distance[start[0]][start[1]] = 0;
        dijkstra(maze);
        return distance[dst_row][dst_col] == numeric_limits<int>::max() ? - 1 : distance[dst_row][dst_col];
    }

private:
    int rows, cols, dst_row, dst_col;
    vector<vector<int>> distance;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dijkstra(vector<vector<int>>& maze) {
        while (true) {
            vector<int> s = minDistance();
            if (s[0] < 0)
                break;
            visited[s[0]][s[1]] = true;
            for (vector<int>& dir: dirs) {
                int r = s[0] + dir[0];
                int c = s[1] + dir[1];
                int count = 0;
                while (r >= 0 && c >= 0 && r < rows && c < cols && maze[r][c] == 0) {
                    r += dir[0];
                    c += dir[1];
                    ++count;
                }
                if (distance[s[0]][s[1]] + count < distance[r - dir[0]][c - dir[1]])
                    distance[r - dir[0]][c - dir[1]] = distance[s[0]][s[1]] + count;
            }
        }
    }
    vector<int> minDistance() {
        vector<int> min = {-1, -1};
        int min_val = numeric_limits<int>::max();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (!visited[row][col] && distance[row][col] < min_val) {
                    min[0] = row, min[1] = col;
                    min_val = distance[row][col];
                }
            }
        }
        return min;
    }
};
