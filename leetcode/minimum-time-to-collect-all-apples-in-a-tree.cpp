// 1443. Minimum Time to Collect All Apples in a Tree
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach: Depth First Search
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       vector<vector<int>> adj(n);
       for (const vector<int>& edge: edges) {
           adj[edge[0]].emplace_back(edge[1]);
           adj[edge[1]].emplace_back(edge[0]);
       }
       return dfs(0, -1, adj, hasApple);
    }

private:
    int dfs(int node, int parent, const vector<vector<int>>& adj, const vector<bool>& has_apple) {
        int total_time = 0, child_time = 0;
        for (const int& child: adj[node]) {
            if (child == parent) {
                continue;
            }
            child_time = dfs(child, node, adj, has_apple);
            if (child_time || has_apple[child]) {
                total_time += child_time + 2;
            }
        }
        return total_time;
    }
};
