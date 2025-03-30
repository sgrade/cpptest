// 2737. Find the Closest Marked Node
// https://leetcode.com/problems/find-the-closest-marked-node/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Dijkstra's Algorithm
class Solution {
    public:
        int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            unordered_set<int> destinations(marked.begin(), marked.end());
            vector<vector<pair<int, int>>> adj(n);
            for (const vector<int>& edge: edges)
                adj[edge[0]].emplace_back(edge[1], edge[2]);

            vector<int> dist(n, numeric_limits<int>::max());
            dist[s] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.emplace(0, s);

            while (!pq.empty()) {
                auto[d, node] = pq.top();
                pq.pop();

                if (destinations.find(node) != destinations.end())
                    return dist[node];

                for (const auto& [neighbor, weight]: adj[node]) {
                    int new_d = d + weight;
                    if (new_d < dist[neighbor]) {
                        dist[neighbor] = new_d;
                        pq.emplace(new_d, neighbor);
                    }
                }
            }

            return -1;
        }
    };
