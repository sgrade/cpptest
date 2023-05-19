// 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach #1: Coloring by Depth-First Search
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1); // -1 - not visited, 0 - group one, 1 - group 2
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1) {
                visited[i] = 0;
                stack<int> st;
                st.emplace(i);
                while (!st.empty()) {
                    int j = st.top();
                    st.pop();
                    for (const int& neigh: graph[j]) {
                        if (visited[neigh] == -1) {
                            st.emplace(neigh);
                            visited[neigh] = !visited[j];
                        }
                        else if (visited[j] == visited[neigh]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
