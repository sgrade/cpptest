// 2492. Minimum Score of a Path Between Two Cities
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 1: Breadth First Search
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const vector<int>& road: roads) {
            adj[road[0]].emplace_back(pair<int, int>(road[1], road[2]));
            adj[road[1]].emplace_back(pair<int, int>(road[0], road[2]));
        }
        return bfs(n, adj);
    }
private:
    int bfs(const int& n, vector<vector<pair<int, int>>>& adj) {
        int ans = numeric_limits<int>::max();

        queue<int> q;
        q.emplace(1);
        vector<bool> visited(n + 1);
        visited[1] = true;

        int node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (const auto& [neighbor, distance]: adj[node]) {
                ans = min(ans, distance);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.emplace(neighbor);
                }
            }
        }

        return ans;
    }
};
