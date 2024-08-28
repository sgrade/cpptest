// 1905. Count Sub Islands
// https://leetcode.com/problems/count-sub-islands/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Union-Find

class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size) {
        iota(parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (x != parent[x])
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    void UnionSet (int x, int y) {
        int root_x = Find(x);   
        int root_y = Find(y);
        if (root_x == root_y)
            return;
        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_y] < rank[root_x])
            parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            ++rank[root_x];
        }
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
    vector<int> parent, rank;
};


class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = grid2.size(), cols = grid2[0].size();
        UnionFind dsu(rows * cols);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid2[row][col] == 1) {
                    int flat_current = Flatten(row, col);
                    for (const auto& [r_diff, c_diff]: directions) {
                        int r = row + r_diff, c = col + c_diff;
                        if (IsValidCell(r, c) && grid2[r][c] == 1) {
                            int flat_neighbor = Flatten(r, c);
                            dsu.UnionSet (flat_current, flat_neighbor);
                        }
                    }
                }
            }
        }

        vector<bool> is_sub_island (rows * cols, true);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid2[row][col] == 1 && grid1[row][col] == 0) {
                    int flat = Flatten(row, col);
                    int parent = dsu.Find(flat);
                    is_sub_island[parent] = false;
                }
            }
        }

        int ans = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid2[row][col] == 1) {
                    int flat = Flatten(row, col);
                    int parent = dsu.Find(flat);
                    if (is_sub_island[parent]) {
                        ++ans;
                        // one cell can be the root of multiple cells
                        is_sub_island[parent] = false;
                    }
                }
            }
        }

        return ans;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    bool IsValidCell (int row, int col) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
    // Convert to one-dimensional
    int Flatten (int row, int col) {
        return row * cols + col;
    }
};
