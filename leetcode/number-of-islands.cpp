// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/
// https://www.youtube.com/watch?v=__98uL6wst8

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i > m-1 || j < 0 || j > n - 1 || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        m = grid.size();
        if (m == 0) return 0;        
        n = grid[0].size();
            
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};
