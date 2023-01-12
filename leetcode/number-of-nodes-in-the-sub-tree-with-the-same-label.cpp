// 1519. Number of Nodes in the Sub-Tree With the Same Label
// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Depth First Search
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> ans(n, 0);
        dfs(0, -1, adj, labels, ans);

        return ans;
    }

private:
    vector<int> dfs(int node, int parent, const vector<vector<int>>& adj, const string& labels, vector<int>& ans) {
        vector<int> node_counts(26);
        int node_index = labels[node] - 'a';
        node_counts[node_index] = 1;

        for (const int& child: adj[node]) {
            if (child == parent) {
                continue;
            }
            vector<int> child_counts = dfs(child, node, adj, labels, ans);
            for (int i = 0; i < 26; ++i) {
                node_counts[i] += child_counts[i];
            }
        }

        ans[node] = node_counts[node_index];
        return node_counts;
    }
};
