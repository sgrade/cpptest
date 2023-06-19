// 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/

#include <bits/stdc++.h>

using namespace std;

// Based on Editorial's Approach 3: Union-Find
class UnionFind {
public:
    UnionFind (int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 1; i < size; ++i)
            parent[i] = i;
    }
    int Find (int x) {
        if (x != parent[x]) 
            parent[x] = Find(parent[x]);
        return parent[x];
    }
    void UnionSet (int x, int y) {
        int root_x = Find(x);
        int root_y = Find(y);
        if (rank[root_x] < rank[root_y])
            parent[root_x] = root_y;
        else if (rank[root_y] < rank[root_x])
            parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            ++rank[root_x];
        }
    }
    bool Connected (const int& x, const int& y) {
        return Find(x) == Find(y);
    }

private:
    vector<int> parent, rank;
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (const vector<int>& v: dislikes) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        UnionFind dsu(n + 1);
        for (int node = 1; node <= n; ++node) {
            for (const int& neighbor: adj[node]) {
                if (dsu.Connected(node, neighbor))
                    return false;
                // adj[node][0] - first neighbor. all other neighbors should be in the same set.
                dsu.UnionSet(adj[node][0], neighbor);
            }
        }
        return true;
    }
};
