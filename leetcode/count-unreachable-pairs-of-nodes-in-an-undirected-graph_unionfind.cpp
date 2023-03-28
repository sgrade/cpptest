// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Breadth First Search
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
                component_size = bfs(i, adj, visited);
                pair_numbers += component_size * (remaining_nodes - component_size);
                remaining_nodes -= component_size;
            }
        }
        return pair_numbers;
    }
private:
    int bfs (int node, vector<vector<int>>& adj, vector<bool>& visited) {
        int component_size = 1;
        visited[node] = true;
        queue<int> q;
        q.emplace(node);
        while (!q.empty()) { 
            node = q.front();
            q.pop();
            for (const int& neighbor: adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    ++component_size;
                    q.emplace(neighbor);
                }
            }
        }
        return component_size;
    }
};
