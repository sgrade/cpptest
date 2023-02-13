// 1129. Shortest Path with Alternating Colors
// https://leetcode.com/problems/shortest-path-with-alternating-colors/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Shortest Path with Alternating Colors
// NOT FINISHED
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // pair.first = source node; pair.second = color (0 - red, 1 - blue)
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& v: redEdges) adj[redEdges[0]].emplace_back(redEdges[1], 0);
        for (const vector<int>& v: blueEdges) adj[blueEdges[0]].emplace_back(blueEdges[1], 1);

        vector<int> ans(n, -1);
        vector<pair<bool, bool>> visited(n, pair<bool, bool>(false, false));
        
        // v[0] = node, v[1] = number of steps, v[2] = color (see above)
        queue<vector<int>> q;
        q.emplace({0, 0, -1});
        visited[0][0] = visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty()) {
            auto[node, element, prev_color]& = q.front();
            q.pop();

            for (const auto)
        }
    }
};
