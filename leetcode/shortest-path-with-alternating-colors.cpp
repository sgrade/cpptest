// 1129. Shortest Path with Alternating Colors
// https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Shortest Path with Alternating Colors
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // pair.first = source node; pair.second = color (0 - red, 1 - blue)
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& v: redEdges) 
            adj[v[0]].emplace_back(pair<int, int>(v[1], 0));
        for (vector<int>& v: blueEdges) 
            adj[v[0]].emplace_back(pair<int, int>(v[1], 1));

        vector<int> ans(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2));
        
        // v[0] = node, v[1] = number of steps, v[2] = color (see above)
        queue<vector<int>> q;
        q.emplace(vector<int>{0, 0, -1});
        visited[0][0] = visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty()) {
            int node = q.front()[0], steps = q.front()[1], prev_color = q.front()[2];
            q.pop();

            for (auto& [neighbor, color] : adj[node]) {
                if (!visited[neighbor][color] && color != prev_color) {
                    visited[neighbor][color] = true;
                    q.emplace(vector<int>{neighbor, steps + 1, color});
                    if (ans[neighbor] == -1) ans[neighbor] = steps + 1;
                }
            }
        }

        return ans;
    }
};
