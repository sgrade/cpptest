// 959. Regions Cut By Slashes
// https://leetcode.com/problems/regions-cut-by-slashes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Union-Find
// Better explanation - https://www.youtube.com/watch?v=tIZkh7mpIDo

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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        UnionFind dsu(n * n * 4);
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                int root = (row * n + col) * 4;
                char val = grid[row][col];
                if (val != '\\') {
                    dsu.UnionSet(root, root + 1);
                    dsu.UnionSet(root + 2, root + 3);
                }
                if (val != '/') {
                    dsu.UnionSet(root, root + 2);
                    dsu.UnionSet(root + 1, root + 3);
                }

                // North - South
                if (row + 1 < n)
                    dsu.UnionSet(root + 3, (root + 4 * n));
                if (row - 1 >= 0)
                    dsu.UnionSet(root, (root - 4 * n) + 3);
                // East - West
                if (col + 1 < n)
                    dsu.UnionSet(root + 2, (root + 4) + 1);
                if (col - 1 >= 0)
                    dsu.UnionSet(root + 1, (root - 4) + 2);
            }
        }

        int ans = 0;
        for (int i = 0; i < n * n * 4; ++i) {
            if (dsu.Find(i) == i)
                ++ans;
        }

        return ans;
    }
};
