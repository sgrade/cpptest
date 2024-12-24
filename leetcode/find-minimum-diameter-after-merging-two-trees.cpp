// 3203. Find Minimum Diameter After Merging Two Trees
// https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Farthest of Farthest (BFS)
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1 = getAdj(n, edges1), adj2 = getAdj(m, edges2);
        int d1 = getDiameter(n, adj1), d2 = getDiameter(m, adj2);
        int combined = ceil(d1 / 2.0) + ceil(d2 / 2.0) + 1;
        return max({d1, d2, combined});
    }
private:
    vector<vector<int>> getAdj(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size);
        for (const auto& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return adj;
    }

    int getDiameter(int n, vector<vector<int>>& adj) {
        auto [farthest, _] = getFarthest(n, adj, 0);
        auto [_, diameter] = getFarthest(n, adj, farthest);
        return diameter;
    }

    pair<int, int> getFarthest(int n, vector<vector<int>>& adj, int source) {
        queue<int> q;
        vector<bool> visited(n);
        q.emplace(source);
        visited[source] = true;

        int max_distance = 0, farthest = source;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int current = q.front();
                q.pop();
                farthest = current;
                for (const int& neighbor: adj[current]) {
                    if (!visited[neighbor]) {
                        q.emplace(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            if (!q.empty())
                ++max_distance;
        }
        return {farthest, max_distance};
    }
};
