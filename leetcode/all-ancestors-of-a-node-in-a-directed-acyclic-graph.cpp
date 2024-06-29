// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <bits/stdc++.h>

using namespace std;


// Approach 2: Depth First Search (Optimized)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ans.resize(n);
        adj.resize(n);
        for (const vector<int>& edge: edges)
            adj[edge[0]].emplace_back(edge[1]);
        for (int i = 0; i < n; ++i)
            dfs(i, i);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<vector<int>> adj;
    void dfs(int ancestor, int node) {
        for (const int& child: adj[node]) {
            if (ans[child].empty() || ans[child].back() != ancestor) {
                ans[child].emplace_back(ancestor);
                dfs(ancestor, child);
            }
        }
    }
};
