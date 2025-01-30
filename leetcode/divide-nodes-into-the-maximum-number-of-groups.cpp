// 2493. Divide Nodes Into the Maximum Number of Groups
// https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: BFS + Union-Find
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        adj.resize(n), parent.resize(n, -1), depth.resize(n);
        for (const vector<int>& edge: edges) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
            Union(edge[0] - 1, edge[1] - 1);
        }

        unordered_map<int, int> groups_for_component;
        for (int node = 0; node < n; ++node) {
            int groups = getGroups(node);
            if (groups == -1)
                return -1;
            int root = getRoot(node);
            groups_for_component[root] = max(groups_for_component[root], groups);
        }

        int ans = 0;
        for (const auto& [root, groups]: groups_for_component)
            ans += groups;
        return ans;
    }

private:
    int n;
    vector<int> parent, depth;
    vector<vector<int>> adj;

    int getRoot(int node) {
        while (parent[node] != -1)
            node = parent[node];
        return node;
    }

    void Union(int node1, int node2) {
        node1 = getRoot(node1);
        node2 = getRoot(node2);
        if (node1 == node2)
            return;
        if (depth[node1] < depth[node2])
            swap(node1, node2);
        parent[node2] = node1;
        if (depth[node1] == depth[node2])
            ++depth[node1];
    }

    int getGroups(int src) {
        queue<int> q;
        vector<int> layer_seen(n, -1);
        q.emplace(src);
        layer_seen[src] = 0;
        int deepest_layer = 0;
        while (!q.empty()) {
            int nodes = q.size();
            for (int i = 0; i < nodes; ++i) {
                int node = q.front();
                q.pop();
                for (const int& neighbor: adj[node]) {
                    if (layer_seen[neighbor] == -1) {
                        layer_seen[neighbor] = deepest_layer + 1;
                        q.emplace(neighbor);
                    }
                    else {
                        if (layer_seen[neighbor] == deepest_layer)
                            return -1;
                    }
                }
            }
            ++deepest_layer;
        }
        return deepest_layer;
    }
};
