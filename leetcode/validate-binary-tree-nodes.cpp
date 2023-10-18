// 1361. Validate Binary Tree Nodes
// https://leetcode.com/problems/validate-binary-tree-nodes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Union Find
class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size) {
        iota(parent.begin(), parent.end(), 0);
        components = size;
    }
    int Find (int x) {
        if (x != parent[x])
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    bool UnionSet (int node, int child) {
        int root_node = Find(node); 
        int root_child = Find(child);
        if (root_child != child || root_node == child)
            return false;
        --components;
        if (rank[root_child] < rank[root_node])
            parent[root_child] = root_node;
        else if (rank[root_node] < rank[root_child])
            parent[root_node] = root_child;
        else {
            parent[root_child] = root_node;
            ++rank[root_child];
        }
        return true;
    }
    bool Connected (int x, int y) {
        return Find(x) == Find(y);
    }
    vector<int> parent, rank;
    int components;
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        UnionFind dsu(n);
        for (int node = 0; node < n; ++node) {
            vector<int> children = {leftChild[node], rightChild[node]};
            for (const int& child: children) {
                if (child == -1)
                    continue;
                if (!dsu.UnionSet(node, child))
                    return false;
            }
        }
        return dsu.components == 1;
    }
};
