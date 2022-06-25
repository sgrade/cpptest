// 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;


// NOTE: it might make sense to try solution with stack instead of recursion and compare
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);
        for (int i = 0; i < n; ++i) {
            if (visited[i] != -1) continue;
            if (!dfs(i, 0, visited, graph)) return false;
        }
        return true;
    }
    
    bool dfs(int idx, int color, vector<int> &visited, const vector<vector<int>>& graph) {
        visited[idx] = color;
        int cur;
        for (int i = 0; i < graph[idx].size(); ++i) {
            cur = graph[idx][i];
            if (visited[cur] == -1) {
                if (!dfs(cur, color ^ 1, visited, graph)) {
                    return false;
                }
            }
            else if (visited[idx] == visited[cur]) {
                return false;
            }
        }
        return true;
    }
};
