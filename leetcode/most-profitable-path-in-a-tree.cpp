// 2467. Most Profitable Path in a Tree
// https://leetcode.com/problems/most-profitable-path-in-a-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Depth-First Search
class Solution {
    public:
        int mostProfitablePath(vector<vector<int>>& edges, int bob,
                               vector<int>& amount) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
    
            n = amount.size(), this->b = bob;
            adj.resize(n), distance_from_b.resize(n);
            for (vector<int> edge : edges) {
                adj[edge[0]].emplace_back(edge[1]);
                adj[edge[1]].emplace_back(edge[0]);
            }
            return getIncome(0, 0, 0, amount);
        }
    
    private:
        int n, b;
        vector<vector<int>> adj;
        vector<int> distance_from_b;
        int getIncome(int node, int parent, int time, vector<int>& amount) {
            int max_income = 0, max_child = INT_MIN;
            if (node == b)
                distance_from_b[node] = 0;
            else
                distance_from_b[node] = n;
    
            for (int neighbor : adj[node]) {
                if (neighbor == parent)
                    continue;
                max_child =
                    max(max_child, getIncome(neighbor, node, time + 1, amount));
                distance_from_b[node] =
                    min(distance_from_b[node], distance_from_b[neighbor] + 1);
            }
    
            if (distance_from_b[node] > time)
                max_income += amount[node];
            else if (distance_from_b[node] == time)
                max_income += amount[node] / 2;
    
            if (max_child == INT_MIN)
                return max_income;
            return max_income + max_child;
        }
    };
    