// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind (int size): parent(size), rank(size) {
        iota (parent.begin(), parent.end(), 0);
    }
    int Find (int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    void UnionSet (int x, int y) {
        int root_x = Find (x), root_y = Find (y);
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
        return;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind dsu (n);
        for (const vector<int>& e: edges)
            dsu.UnionSet (e[0], e[1]);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans += i == dsu.parent[i] ? 1 : 0;
        return ans;
    }
};
