// 2699. Modify Graph Edge Weights
// https://leetcode.com/problems/modify-graph-edge-weights/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Traditional Dijkstra's algorithm
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        src = source, dst = destination;
        
        long long current_shortest_distance = Dijkstra (edges);
        if (current_shortest_distance < target)
            return {};
        
        bool matches_target = current_shortest_distance == target;
        for (vector<int>& edge: edges) {
            if (edge[2] > 0)
                continue;
            edge[2] = matches_target ? max_weight : 1;
            if (!matches_target) {
                long long new_distance = Dijkstra (edges);
                if (new_distance <= target) {
                    matches_target = true;
                    edge[2] += target - new_distance;
                }
            }
        }
        return matches_target ? edges : vector<vector<int>>{};
    }

private:
    int n, src, dst, max_weight = 2e9;
    long long Dijkstra (const vector<vector<int>>& edges) {
        vector<vector<long long>> adj (n, vector<long long>(n, max_weight));
        vector<long long> min_distance (n, max_weight);
        vector<bool> visited (n);
        min_distance[src] = 0;
        for (const vector<int>& edge: edges) {
            if (edge[2] != -1) {
                adj[edge[0]][edge[1]] = edge[2];
                adj[edge[1]][edge[0]] = edge[2];
            }
        }
        for (int i = 0; i < n; ++i) {
            int nearest_unvisited_node = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (
                    nearest_unvisited_node == -1 || min_distance[j] < min_distance[nearest_unvisited_node]
                )) {
                    nearest_unvisited_node = j;
                }
            }
            visited[nearest_unvisited_node] = true;
            for (int v = 0; v < n; ++v) {
                min_distance[v] = min (min_distance[v], min_distance[nearest_unvisited_node] + adj[nearest_unvisited_node][v]);
            }
        }
        return min_distance[dst];
    }
};
