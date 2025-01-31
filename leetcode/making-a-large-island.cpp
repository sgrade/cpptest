// 827. Making A Large Island
// https://leetcode.com/problems/making-a-large-island/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Using DFS
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        rows = grid.size(), cols = grid[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1)
                    id_to_size[island_id++] = traverse(grid, row, col);
            }
        }

        if (id_to_size.empty())
            return 1;
        if (id_to_size.size() == 1) {
            --island_id;
            return id_to_size[island_id] == rows * cols ? id_to_size[island_id] : id_to_size[island_id] + 1;
        }

        int ans = 1;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    int current_ans = 1;
                    unordered_set<int> neighbors;
                    if (row + 1 < rows && grid[row + 1][col] > 1)
                        neighbors.emplace(grid[row + 1][col]);
                    if (row - 1 >= 0 && grid[row - 1][col] > 1)
                        neighbors.emplace(grid[row - 1][col]);
                    if (col + 1 < cols && grid[row][col + 1] > 1)
                        neighbors.emplace(grid[row][col + 1]);
                    if (col - 1 >= 0 && grid[row][col - 1] > 1)
                        neighbors.emplace(grid[row][col - 1]);
                    for (const int& neighbor: neighbors)
                        current_ans += id_to_size[neighbor];
                    ans = max(ans, current_ans);
                }
            }
        }
        return ans;
    }

private:
    int rows, cols, island_id = 2;
    unordered_map<int, int> id_to_size;
    int traverse(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] != 1)
            return 0;
        grid[row][col] = island_id;
        int left = traverse(grid, row - 1, col);
        int right = traverse(grid, row + 1, col);
        int up = traverse(grid, row, col - 1);
        int down = traverse(grid, row, col + 1);
        return 1 + left + right + up + down;
    }
};
