// 1245. Tree Diameter
// https://leetcode.com/problems/tree-diameter/

#include <bits/stdc++.h>

using namespace std;


// Fixed with Editorial's Approach 3: DFS (Depth-First Search)
class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        
        int a = 0;
        vector<bool> visited(n);
        dfs(0, visited, adj);
        return ans;
    }
private:
    int n;
    int ans = 0;
    int dfs(int node, vector<bool>& visited, const vector<vector<int>>& adj) {
        visited[node] = true;
        int max_d = 0, second_max_d = 0;
        for (const int& neighbor: adj[node]) {
            int current_depth = 0;
            if (!visited[neighbor])
                current_depth = 1 + dfs(neighbor, visited, adj);
            if (current_depth > max_d) {
                second_max_d = max_d;
                max_d = current_depth;
            }
            else if (current_depth > second_max_d)
                second_max_d = current_depth;
        }
        ans = max(ans, max_d + second_max_d);
        return max_d;
    }
};
