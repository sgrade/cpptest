// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> neighbors(n);
        for (const vector<int>& edge: edges) {
            neighbors[edge[0]].emplace_back(edge[1]);
            neighbors[edge[1]].emplace_back(edge[0]);
        }
        stack<int> st;
        st.emplace(source);
        vector<bool> visited(n);
        visited[source] = true;
        while (!st.empty()) {
            int candidate = st.top();
            st.pop();
            if (candidate == destination)
                    return true;
            for (const int& neighbor: neighbors[candidate]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.emplace(neighbor);
                }
            }
        }
        return false;
    }
};
