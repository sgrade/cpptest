// 684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First Search - Brute Force
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = edges.size();
        adj.resize(n);
        for (const vector<int>& edge: edges) {
            vector<bool> visited(n);
            if (isConnected(edge[0] - 1, edge[1] - 1, visited))
                return edge;
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
        }
        return {};
    }

private:
    int n;
    vector<vector<int>> adj;
    bool isConnected(int src, int dst, vector<bool>& visited) {
        visited[src] = true;
        if (src == dst)
            return true;
        int is_found = false;
        for (int neighbor: adj[src]) {
            if (!visited[neighbor])
                is_found = is_found || isConnected(neighbor, dst, visited);
        }
        return is_found;
    }
};
