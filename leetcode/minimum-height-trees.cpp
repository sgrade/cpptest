// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>

using namespace std;


// TLE
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (const vector<int>& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        heights;
        for (int i = 0; i < n; ++i)
            bfs(i);
        
        sort(heights.begin(), heights.end());
        int max_height = heights[0].first;
        vector<int> ans = {heights[0].second};
        for (size_t i = 1; i < heights.size() && heights[i].first == max_height; ++i) {
            ans.emplace_back(heights[i].second);
        }
        return ans;
    }
private:
    int n;
    vector<vector<int>> adj;
    vector<pair<int, int>> heights;
    void bfs(int root) {
        int height = 0;
        // node, height
        queue<pair<int, int>> q;
        q.emplace(root, 0);
        vector<bool> visited(n);
        while (!q.empty()) {
            int node = q.front().first;
            int current_height = q.front().second + 1;
            q.pop();
            visited[node] = true;
            height = max(height, current_height);
            if (adj[node].empty()) {
                continue;
            }
            for (const int& neighbor: adj[node]) {
                if (visited[neighbor])
                    continue;
                q.emplace(neighbor, current_height);
            }
        }
        heights.emplace_back(height, root);
    }
};
