// 2101. Detonate the Maximum Bombs
// https://leetcode.com/problems/detonate-the-maximum-bombs/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First Search, Recursive
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();

        // Build the graph
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                long xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                long xj = bombs[j][0], yj = bombs[j][1];

                if (ri * ri >= (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj))
                    graph[i].emplace(j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n);
            int cnt = dfs(i, visited);
            ans = max(ans, cnt);
        }

        return ans;
    }

private:
    map<int, unordered_set<int>> graph;
    int n;

    int dfs(int current, vector<bool>& visited) {
        visited[current] = true;
        int cnt = 1;
        for (int neighbor : graph[current]) {
            if (!visited[neighbor])
                cnt += dfs(neighbor, visited);
        }
        return cnt;
    }
};
