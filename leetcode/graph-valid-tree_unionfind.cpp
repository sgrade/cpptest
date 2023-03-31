// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/

#include <bits/stdc++.h>

using namespace std;


// An idea how to use UnionFind here is from Editorial's Approach 3: Advanced Graph Theory + Union Find
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
    bool UnionSet (int x, int y) {
        int root_x = Find(x); 
        int root_y = Find(y);
        if (root_x == root_y)
            // If a merge didn't happen, it means the two nodes were already connected.
            // So, if we connect them again, there will be a cycle. There are no cycles in a tree.
            return false;
        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_y] < rank[root_x])
            parent[root_y] = root_x;
        else {
            parent[root_x] = root_y;
            ++rank[root_y];
        }
        return true;
    }
    bool Connected (int x, int y);
    vector<int> parent, rank;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n -1 != edges.size())
            return false;
        UnionFind dsu (n);
        for (const vector<int>& edge: edges) {
            if (!dsu.UnionSet (edge[0], edge[1]))
                return false;
        }
        return true;
    }
};
