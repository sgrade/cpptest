// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Depth-First Search (DFS)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
        int ans = 0;

        vector<vector<int>> adj(n);
        for (const vector<int>& v: edges) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(adj, visited, i);
            }
        }

        return ans;
    }

private:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visited, int i) {
        visited[i] = true;
        for (const int& node: adj[i]) {
            if (!visited[node]) {
                dfs(adj, visited, node);
            }
        }
    }
};
