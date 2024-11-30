// 2097. Valid Arrangement of Pairs
// https://leetcode.com/problems/valid-arrangement-of-pairs/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Eulerian Path (Recursive)
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        for (const vector<int>& pair: pairs) {
            int start = pair[0], end = pair[1];
            adj[start].emplace(end);
            ++outdegree[start];
            ++indegree[end];
        }

        int start_node = -1;
        for (const auto& [node, node_outs]: outdegree) {
            int node_ins = indegree[node];
            if (node_outs == node_ins + 1) {
                start_node = node;
                break;
            }
        }
        if (start_node == -1)
            start_node = pairs[0][0];

        visit(start_node);

        reverse(order.begin(), order.end());
        vector<vector<int>> ans;
        for (int i = 1; i < order.size(); ++i)
            ans.emplace_back(vector<int>{order[i - 1], order[i]});
        return ans;
    }

private:
        unordered_map<int, queue<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        vector<int> order;
        void visit(int node) {
            while (!adj[node].empty()) {
                int next = adj[node].front();
                adj[node].pop();
                visit(next);
            }
            order.emplace_back(node);
        }
};
