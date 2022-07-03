// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// https://www.youtube.com/watch?v=__98uL6wst8

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int rows, columns;
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i > rows - 1 || j < 0 || j > columns - 1 || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        rows = grid.size();
        if (rows == 0) return 0;        
        columns = grid[0].size();
            
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};
