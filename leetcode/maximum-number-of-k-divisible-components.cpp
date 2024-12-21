// 2872. Maximum Number of K-Divisible Components
// https://leetcode.com/problems/maximum-number-of-k-divisible-components/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Breadth-First Search (BFS)
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n, this->k = k;
        if (n < 2)
            return 1;
        for (const vector<int>& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            adj[node1].insert(node2);
            adj[node2].insert(node1);
        }

        vector<long long> vals(values.begin(), values.end());
        queue<int> q;
        for (const auto& [node, neighbors]: adj) {
            if (neighbors.size() == 1)
                q.emplace(node);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int neighbor = adj[node].empty() ? -1 : *adj[node].begin();
            if (neighbor >= 0) {
                adj[neighbor].erase(node);
                adj[node].erase(neighbor);
            }
            if (vals[node] % k == 0)
                ++ans;
            else if (neighbor >= 0)
                vals[neighbor] += vals[node];
            
            if (neighbor >= 0 && adj[neighbor].size() == 1)
                q.emplace(neighbor);
        }

        return ans;
    }

private:
    int n, k, ans = 0;
    map<int, set<int>> adj;
};
