// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Depth First Search
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        long long pair_numbers = 0;
        long long component_size = 0;
        long long remaining_nodes = n;
        vector<bool> visited(n);
        for (size_t i = 0; i < n; ++i) {
            if (!visited[i]) {
                component_size = dfs(i, adj, visited);
                pair_numbers += component_size * (remaining_nodes - component_size);
                remaining_nodes -= component_size;
            }
        }
        return pair_numbers;
    }
private:
    int dfs (const int& node, vector<vector<int>>& adj, vector<bool>& visited) {
        int component_size = 1;
        visited[node] = true;
        for (const int& neighbor: adj[node]) 
            if (!visited[neighbor])
                component_size += dfs (neighbor, adj, visited);
        return component_size;
    }
};
