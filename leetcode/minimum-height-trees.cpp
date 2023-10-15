// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Topological Sorting
// Optimized with ideas from Sample 87 ms submission
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n < 2) {
            for (int i = 0; i < n; ++i)
                ans.emplace_back(i);
            return ans;
        }

        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (const vector<int>& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
            ++indegree[e[0]];
            ++indegree[e[1]];
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1)
                leaves.emplace(i);
        }

        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            int k = leaves.size();
            remaining_nodes -= k;
            for (int i = 0; i < k; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                --indegree[leaf];
                for (const int& neighbor: adj[leaf]) {
                    --indegree[neighbor];
                    if (indegree[neighbor] == 1)
                        leaves.emplace(neighbor);
                }
            }
        }

        while (!leaves.empty()) {
            ans.emplace_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};
