// 834. Sum of Distances in Tree
// https://leetcode.com/problems/sum-of-distances-in-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #1: Subtree Sum and Count
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->n = n;
        ans.resize(n);
        count.resize(n, 1);
        graph.resize(n);

        for (const vector<int>& edge: edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
private:
    int n;
    vector<int> ans, count;
    vector<vector<int>> graph;
    void dfs (int node, int parent) {
        for (const int& child: graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    void dfs2 (int node, int parent) {
        for (const int& child: graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + n - count[child];
                dfs2(child, node);
            }
        }
    }
};
