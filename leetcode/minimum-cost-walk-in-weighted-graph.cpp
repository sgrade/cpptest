// 3108. Minimum Cost Walk in Weighted Graph
// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Depth-First Search (DFS)
class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            adj.resize(n);
            for (const vector<int>& e: edges) {
                adj[e[0]].emplace_back(e[1], e[2]);
                adj[e[1]].emplace_back(e[0], e[2]);
            }

            visited.resize(n);
            components.resize(n);
            vector<int> component_cost;
            int component = 0;
            for (int node = 0; node < n; ++node) {
                if (!visited[node]) {
                    component_cost.emplace_back(getComponentCost(node, component));
                    ++component;
                }
            }

            vector<int> ans;
            for (const vector<int>& q: query) {
                int start = q[0], end = q[1];
                if (components[start] == components[end])
                    ans.emplace_back(component_cost[components[start]]);
                else
                    ans.emplace_back(-1);
            }
            return ans;
        }

    private:
        vector<vector<pair<int, int>>> adj;
        vector<bool> visited;
        vector<int> components;

        int getComponentCost(int node, int component) {
            int cost = INT_MAX;
            components[node] = component;
            visited[node] = true;
            for (const auto& [neighbor, weight]: adj[node]) {
                cost &= weight;
                if (!visited[neighbor])
                    cost &= getComponentCost(neighbor, component);
            }
            return cost;
        }
    };
