// 3373. Maximize the Number of Target Nodes After Connecting Trees II
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Depth-First Search
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<int> colors1(n1), colors2(n2);
        vector<int>
        targets1 = getTargets(edges1, colors1),
        targets2 = getTargets(edges2, colors2);
        vector<int> ans(n1);
        for (int i = 0; i < n1; ++i)
            ans[i] = targets1[colors1[i]] + max(targets2[0], targets2[1]);
        return ans;
    }

private:
    vector<int> getTargets(const vector<vector<int>>& edges, vector<int>& colors) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const vector<int>& e: edges) {
            children[e[0]].emplace_back(e[1]);
            children[e[1]].emplace_back(e[0]);
        }
        int ans = dfs(0, -1, 0, children, colors);
        return {ans, n - ans};
    }

    int dfs(int node, int parent, int depth, const vector<vector<int>>& children, vector<int>& colors) {
        int ans = 1 - depth % 2;
        colors[node] = depth % 2;
        for (const int& child: children[node]) {
            if (child == parent)
                continue;
            ans += dfs(child, node, depth + 1, children, colors);
        }
        return ans;
    }
};
