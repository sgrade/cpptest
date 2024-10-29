// 2684. Maximum Number of Moves in a Grid
// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Breadth-First Search (BFS)
class Solution {
public:
    int rows, cols;
    vector<int> dirs = {-1, 0, 1};

    int maxMoves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int row = 0; row < rows; ++row) {
            visited[row][0] = true;
            q.emplace(vector<int>{row, 0, 0});
        }

        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                vector<int> v = q.front();
                q.pop();
                int row = v[0], col = v[1], current_ans = v[2];
                ans = max(ans, current_ans);
                for (const int& dir: dirs) {
                    int r = row + dir, c = col + 1;
                    if (r >= 0 &&
                        c >= 0 &&
                        r < rows &&
                        c < cols &&
                        !visited[r][c] &&
                        grid[row][col] < grid[r][c]
                    ){
                        visited[r][c] = true;
                        q.emplace(vector<int>{r, c, current_ans + 1});
                    }
                }
            }
        }

        return ans;
    }
};
