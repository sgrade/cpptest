// Approach 1: Topological Sort Using Kahn's Algorithm
// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Topological Sort Using Kahn's Algorithm
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (const int& node: graph[i]) {
                adj[node].emplace_back(i);
                ++indegree[i];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (const int& neighbor: adj[node]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};
