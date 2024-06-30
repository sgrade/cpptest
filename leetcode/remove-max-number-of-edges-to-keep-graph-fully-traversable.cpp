// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Disjoint Set Union (DSU)
class UnionFind {
public:
    UnionFind (int size): parent(size + 1), component_size(size + 1) {
        components = size;
        iota(parent.begin(), parent.end(), 0);
        fill(component_size.begin(), component_size.end(), 1);
    }
    int Find (int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    int UnionSet (int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return 0;
        if (component_size[x] > component_size[y]) {
            component_size[x] += component_size[y];
            parent[y] = x;
        }
        else {
            component_size[y] += component_size[x];
            parent[x] = y;
        }
        --components;
        return 1;
    }
    bool Connected () {
        return components == 1;
    }
    vector<int> parent, component_size;
    int components;
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        UnionFind Alice(n);
        UnionFind Bob(n);
        int edges_need = 0;
        for (const vector<int>& edge: edges) {
            if (edge[0] == 3) {
                int alice_need = Alice.UnionSet(edge[1], edge[2]);
                int bob_need = Bob.UnionSet(edge[1], edge[2]);
                edges_need += (alice_need | bob_need);
            }
        }
        for (const vector<int>& edge: edges) {
            if (edge[0] == 1)
                edges_need += Alice.UnionSet(edge[1], edge[2]);
            else if (edge[0] == 2)
                edges_need += Bob.UnionSet(edge[1], edge[2]);
        }
        if (Alice.Connected() && Bob.Connected()) {
            return edges.size() - edges_need;
        }
        return -1;
    }
};
