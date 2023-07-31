// 1319. Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <bits/stdc++.h>

using namespace std;


// Based on Approach 1: Depth First Search
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        
        adj.resize(n);
        visited.resize(n);

        for (const vector<int>& c: connections) {
            adj[c[0]].emplace_back(c[1]);
            adj[c[1]].emplace_back(c[0]);
        }

        int num_of_connected_components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++num_of_connected_components;
                dfs(i);
            }
        }

        return num_of_connected_components - 1;
    }

private:
    vector<vector<int>> adj;
    vector<bool> visited;
    void dfs(int node) {
        visited[node] = true;
        for (const int& neighbor: adj[node]) {
            if (!visited[neighbor])
                dfs(neighbor);
        }
    }
};
