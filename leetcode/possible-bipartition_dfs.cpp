// 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/

#include <bits/stdc++.h>

using namespace std;

// Based on Editorial's Approach 2: Depth First Search
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> adj(n + 1);
        for (const vector<int>& v: dislikes) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        vector<int> color(n + 1, -1);
        for (int source = 1; source <= n; ++source) {
            if (color[source] == -1) {
                if (!dfs(source, adj, color))
                    return false;
            }
        }
        return true;
    }

private:
    bool dfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        stack<int> st;
        st.emplace(source);
        color[source] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (const int& neighbor : adj[node]){
                if (color[neighbor] == color[node])
                    return false;
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    st.emplace(neighbor);
                }
            }
        }
        return true;
    }
};
