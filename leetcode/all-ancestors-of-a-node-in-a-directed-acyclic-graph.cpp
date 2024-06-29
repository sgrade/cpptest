// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Topological Sort (BFS)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (const vector<int>& edge: edges) {
            const int& from = edge[0];
            const int& to = edge[1];
            adj[from].emplace_back(to);
            ++indegree[to];
        }

        // Nodes with zero indegree
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        vector<int> topological_order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topological_order.emplace_back(node);
            for (const int& neighbor: adj[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        vector<set<int>> ancestors(n);
        for (const int& node: topological_order) {
            for (const int& neighbor: adj[node]) {
                ancestors[neighbor].emplace(node);
                ancestors[neighbor].insert(ancestors[node].begin(), ancestors[node].end());
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = vector<int> (ancestors[i].begin(), ancestors[i].end());
        return ans;
    }
};
