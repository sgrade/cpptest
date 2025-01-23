// 1267. Count Servers that Communicate
// https://leetcode.com/problems/count-servers-that-communicate/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> servers_in_row(rows), servers_in_col(cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    ++servers_in_row[row];
                    ++servers_in_col[col];
                }
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    if (servers_in_row[row] > 1)
                        ++ans;
                    else if (servers_in_col[col] > 1)
                        ++ans;
                }
            }
        }
        return ans;
    }
};
