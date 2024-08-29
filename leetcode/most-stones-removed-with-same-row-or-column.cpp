// 947. Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        n = stones.size();
        adj.resize(n, vector<int>(n));
        visited.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i);
                ++components;
            }
        }
        return n - components;
    }

private:
    int n;
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
