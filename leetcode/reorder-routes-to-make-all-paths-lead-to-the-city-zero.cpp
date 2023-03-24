// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Depth First Search
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& connection: connections) {
            adj[connection[0]].emplace_back(pair<int, int>(connection[1], 1));
            adj[connection[1]].emplace_back(pair<int, int>(connection[0], 0)); 
        }
        dfs (0, -1, adj);
        return ans;
    }
private:
    int ans = 0;
    void dfs (const int& node, const int& parent, vector<vector<pair<int, int>>>& adj) {
        for (const auto& [child, need_to_flip]: adj[node]) {
            if (child != parent) {
                ans += need_to_flip;
                dfs (child, node, adj);
            }
        }
    }
};
