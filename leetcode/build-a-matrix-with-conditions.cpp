// 2392. Build a Matrix With Conditions
// https://leetcode.com/problems/build-a-matrix-with-conditions/

#include <bits/stdc++.h>

using namespace std;


// Based on Editotorial's Approach 2: Kahn's Algorithm
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->k = k;
        vector<int> order_rows = topoSort(rowConditions);
        vector<int> order_cols = topoSort(colConditions);
        if (order_rows.empty() || order_cols.empty())
            return {};
        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (order_rows[i] == order_cols[j])
                    ans[i][j] = order_rows[i];
            }
        }
        return ans;
    }

private:
    int k;
    vector<int> topoSort(vector<vector<int>>& edges) {
        int n = k + 1;
        vector<vector<int>> adj(n);
        vector<int> indegree(n), order;
        for (const vector<int>& edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
            ++indegree[edge[1]];
        }
        queue<int> q;
        for (int i = 1; i < n; ++i)
            if (indegree[i] == 0) q.emplace(i);
        while (!q.empty()) {
            int source = q.front();
            q.pop();
            order.emplace_back(source);
            --n;
            for (const int& destination: adj[source]) {
                if (--indegree[destination] == 0)
                    q.emplace(destination);
            }
        }
        if (n != 1)
            return {};
        return order;
    }
};
