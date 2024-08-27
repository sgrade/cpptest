// 1514. Path with Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int start = edges[i][0], end = edges[i][1];
            adj[start].emplace_back(end, succProb[i]);
            adj[end].emplace_back(start, succProb[i]);
        }
        
        vector<double> max_prob(n);
        max_prob[start_node] = 1.0;
        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);
        while (!pq.empty()) {
            pair<double, int> p = pq.top();
            double current_prob = p.first;
            int current_node = p.second;
            pq.pop();
            if (current_node == end_node)
                return current_prob;
            for (const auto& [neighbor, edge_prob]: adj[current_node]) {
                double neighbor_prob = current_prob * edge_prob;
                if (neighbor_prob > max_prob[neighbor]) {
                    max_prob[neighbor] = neighbor_prob;
                    pq.emplace(neighbor_prob, neighbor);
                }
            }
        }
        return 0.0;
    }
};
