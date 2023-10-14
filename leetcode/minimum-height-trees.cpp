// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>

using namespace std;


// VERY SLOW
// Based on Editorial's Approach 1: Topological Sorting
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n < 2) {
            for (int i = 0; i < n; ++i)
                ans.emplace_back(i);
            return ans;
        }

        this->n = n;
        adj.resize(n);
        for (const vector<int>& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1)
                leaves.emplace(i);
        }

        int remaining_nodes = n;
        while (remaining_nodes > 2) {
            remaining_nodes -= leaves.size();
            queue<int> new_leaves;
            while (!leaves.empty()) {
                int leaf = leaves.front();
                leaves.pop();
                int neighbor = adj[leaf][0];
                vector<int>& neighbors = adj[neighbor];
                // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
                neighbors.erase(remove(neighbors.begin(), neighbors.end(), leaf), neighbors.end());
                if (neighbors.size() == 1)
                    new_leaves.emplace(neighbor);
            }
            leaves = new_leaves;
        }

        while (!leaves.empty()) {
            ans.emplace_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
private:
    int n;
    vector<int> ans;
    vector<vector<int>> adj;
};
