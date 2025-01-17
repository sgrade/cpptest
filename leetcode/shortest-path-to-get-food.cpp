// 1730. Shortest Path to Get Food
// https://leetcode.com/problems/shortest-path-to-get-food/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == '*') {
                    start.first = row, start.second = col;
                    break;
                }
            }
        }

        visited.resize(rows, vector<bool>(cols));
        queue<pair<int, int>> q;
        q.emplace(start.first, start.second);
        int moves = 0;
        while (!q.empty()) {
            int n = q.size();
            while(n--) {
                auto [row, col] = q.front();
                q.pop();
                if (grid[row][col] == '#')
                    return moves;
                visited[row][col] = true;
                for (auto& [r_diff, c_diff]: directions) {
                    int r = row + r_diff, c = col + c_diff;
                    if (IsValid(r, c, grid))
                        q.emplace(r, c);
                }
            }
            ++moves;
        }

        return -1;
    }

private:
    int rows, cols;
    pair<int, int> start;
    vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0}, 
        {-1, 0}
    };
    vector<vector<bool>> visited;
    bool IsValid(int r, int c, vector<vector<char>>& grid) {
        return r < rows && c < cols && r >= 0 && c >= 0 && !(grid[r][c] == 'X') && !visited[r][c];
    }
};
