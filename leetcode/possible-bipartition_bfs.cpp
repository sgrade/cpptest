// 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/

#include <bits/stdc++.h>

using namespace std;

// Based on Editorial's Approach 1: Breadth First Search
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (const vector<int>& v: dislikes) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        vector<int> color(n + 1, -1);
        for (int source = 1; source <= n; ++source) {
            if (color[source] == -1) {
                if (!bfs(source, adj, color))
                    return false;
            }
        }
        return true;
    }

private:
    bool bfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        queue<int> q;
        q.emplace(source);
        color[source] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (const int& neighbor : adj[node]){
                if (color[neighbor] == color[node])
                    return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.emplace(neighbor);
                }
            }
        }
        return true;
    }
};
