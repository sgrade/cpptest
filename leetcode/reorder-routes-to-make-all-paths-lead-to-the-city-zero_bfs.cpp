// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Breadth First Search
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& connection: connections) {
            adj[connection[0]].emplace_back(pair<int, int>(connection[1], 1));
            adj[connection[1]].emplace_back(pair<int, int>(connection[0], 0)); 
        }
        bfs(0, n, adj);
        return ans;
    }
private:
    int ans = 0;
    void bfs (int node, int& n, vector<vector<pair<int, int>>>& adj) {
        queue<int> q;
        vector<bool> visited(n);
        q.emplace(node);
        visited[node] = true;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (const auto& [neighbor, need_to_flip]: adj[node]) {
                if (!visited[neighbor]) {
                    ans += need_to_flip;
                    visited[neighbor] = true;
                    q.emplace(neighbor);
                }
            }
        }
    }
};
