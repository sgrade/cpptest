// 2492. Minimum Score of a Path Between Two Cities
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

#include <bits/stdc++.h>

using namespace std;


// Modified the bfs code for dfs
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const vector<int>& road: roads) {
            adj[road[0]].emplace_back(pair<int, int>(road[1], road[2]));
            adj[road[1]].emplace_back(pair<int, int>(road[0], road[2]));
        }
        return dfs(n, adj);
    }
private:
    int dfs(const int& n, vector<vector<pair<int, int>>>& adj) {
        int ans = numeric_limits<int>::max();

        stack<int> st;
        st.emplace(1);
        vector<bool> visited(n + 1);
        visited[1] = true;

        int node;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            for (const auto& [neighbor, distance]: adj[node]) {
                ans = min(ans, distance);
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.emplace(neighbor);
                }
            }
        }

        return ans;
    }
};
