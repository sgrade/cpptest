// 1857. Largest Color Value in a Directed Graph
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Topological Sort Using Kahn's Algorithm
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = colors.size();
        indegree.resize(n);
        adj.resize(n);
        for (const vector<int>& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            ++indegree[e[1]];
        }

        counter.resize(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        int ans = 0, visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans = max(ans, ++counter[node][colors[node] - 'a']);
            ++visited;

            for (const int& neighbor: adj[node]) {
                for (int i = 0; i < 26; ++i)
                    counter[neighbor][i] = max(counter[neighbor][i], counter[node][i]);
                --indegree[neighbor];
                if (indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        return visited < n ? -1 : ans;
    }

private:
    int n;
    vector<int> indegree;
    vector<vector<int>> adj, counter;
};
