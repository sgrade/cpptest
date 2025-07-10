// 3607. Power Grid Maintenance
// https://leetcode.com/problems/power-grid-maintenance/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/power-grid-maintenance/solutions/6926265/no-dsu-needed-simple-dfs-easy-approach
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        adj.resize(c + 1);
        for (const vector<int>& connection: connections) {
            adj[connection[0]].emplace_back(connection[1]);
            adj[connection[1]].emplace_back(connection[0]);
        }

        vector<bool> visited(c + 1);
        component_ids.resize(c + 1);
        for (int node = 1; node <= c; ++node) {
            if (!visited[node])
                dfs(node, visited, node);
        }

        vector<int> ans;
        for (const vector<int>& q: queries) {
            int node = q[1];
            int component_id = component_ids[node];
            set<int>& neighbors = connected[component_id];

            if (q[0] == 1) {
                if (neighbors.count(node))
                    ans.emplace_back(node);
                else if (!neighbors.empty())
                    ans.emplace_back(*neighbors.begin());
                else
                    ans.emplace_back(-1);
            }
            else {
                if (neighbors.count(node))
                    neighbors.erase(node);
            }
        }
        return ans;
    }

private:
    vector<vector<int>> adj;
    unordered_map<int, set<int>> connected;
    vector<int> component_ids;
    void dfs(int node, vector<bool>& visited, int component_id) {
        visited[node] = true;
        component_ids[node] = component_id;
        connected[component_id].emplace(node);
        for (const int& neighbor: adj[node]) {
            if (visited[neighbor])
                continue;
            dfs(neighbor, visited, component_id);
        }
    }
};
