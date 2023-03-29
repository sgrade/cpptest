// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 3: Union-find
class UnionFind {
public:
    UnionFind (int size): parent(size), rank(size, 0) {
        iota (parent.begin(), parent.end(), 0);
    }
    int find (int x) {
        while (x != parent[x])
            x = parent[x];
        return x;
    }
    void UnionSet (int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset)
            return;
        else if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            ++rank[xset];
        }
    }
private:
    vector<int> parent, rank;
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind dsu(n);
        for (const vector<int>& edge: edges)
            dsu.UnionSet(edge[0], edge[1]);
        unordered_map<int, int> component_size;
        for (int i = 0; i < n; ++i)
            ++component_size[dsu.find(i)];
        
        long long pair_numbers = 0;
        long long remaining_nodes = n;
        int current_size;
        for (const auto& [component, size]: component_size) {
            current_size = size;
            pair_numbers += size * (remaining_nodes - size);
            remaining_nodes -= size;
        }
        return pair_numbers;
    }
};
