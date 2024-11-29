// 2204. Distance to a Cycle in Undirected Graph
// https://leetcode.com/problems/distance-to-a-cycle-in-undirected-graph/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First Search (DFS)
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        is_in_cycle.resize(n), visited.resize(n);
        parent.resize(n), distances.resize(n);
        adj.resize(n);
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        getCycleNodes(0);

        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n; ++i) {
            if (is_in_cycle[i]) {
                getDistances(i, 0);
                break;
            }
        }
        return distances;
    }

private:
    int n;
    vector<bool> is_in_cycle, visited;
    vector<int> parent, distances;
    vector<vector<int>> adj;

    bool getCycleNodes(int node) {
        visited[node] = true;
        for (const int& neighbor: adj[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                if (getCycleNodes(neighbor))
                    return true;
            }
            else if (parent[node] != neighbor) {
                is_in_cycle[neighbor] = true;
                int temp = node;
                while (temp != neighbor) {
                    is_in_cycle[temp] = true;
                    temp = parent[temp];
                }
                return true;
            }
        }
        return false;
    }

    void getDistances (int node, int distance) {
        distances[node] = distance;
        visited[node] = true;
        for (const int& neighbor: adj[node]) {
            if (visited[neighbor])
                continue;
            int new_dist = is_in_cycle[neighbor] ? 0 : distance + 1;
            getDistances (neighbor, new_dist);
        }
    }
};
