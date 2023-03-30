// 547. Number of Provinces
// https://leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>

using namespace std;


class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind (int size): parent(size), rank(size) {
        iota (parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }
    void UnionSet (int x, int y) {
        int parent_x = Find(x), parent_y = Find(y);
        if (parent_x == parent_y)
            return;
        else if (rank[parent_x] < rank[parent_y])
            parent[parent_x] = parent_y;
        else if (rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else {
            parent[parent_y] = parent[x];
            ++rank[parent[x]];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t rows = isConnected.size(), cols = isConnected[0].size();
        UnionFind dsu(rows);
        for (size_t row = 0; row < rows; ++row) {
            for (size_t col = 0; col < cols; ++col) {
                if (isConnected[row][col] == 1 && row != col)
                    dsu.UnionSet(row, col);
            }
        }
        int ans = 0;
        for (int i = 0; i < dsu.parent.size(); ++i)
            ans += (i == dsu.parent[i]);
        return ans;
    }
};
