// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 2: Advanced Graph Theory + Iterative Depth-First Search
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj_list(n);
        for (const vector<int>& v: edges) {
            adj_list[v[0]].emplace_back(v[1]);
            adj_list[v[1]].emplace_back(v[0]);
        }

        // DFS iterative
        stack<int> nodes;
        unordered_set<int> seen;
        nodes.emplace(0);
        seen.emplace(0);

        int node;
        while (!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
            for (const int& neighbor: adj_list[node]) {
                if (seen.find(neighbor) != seen.end()) {
                    continue;
                }
                seen.emplace(neighbor);
                nodes.emplace(neighbor);
            }
        }

        return seen.size() == n;
    }
};
