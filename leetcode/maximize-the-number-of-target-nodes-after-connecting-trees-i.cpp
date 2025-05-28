// 3372. Maximize the Number of Target Nodes After Connecting Trees I
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Depth-First Search
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        n1 = edges1.size() + 1;
        vector<int> targets1 = getTargets(edges1, k);
        vector<int> targets2 = getTargets(edges2, k - 1);
        int mx2 = *max_element(targets2.begin(), targets2.end());
        vector<int> ans(n1);
        for (int i = 0; i < n1; ++i)
            ans[i] = targets1[i] + mx2;
        return ans;
    }

private:
    int n1;

    vector<int> getTargets(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const vector<int>& e: edges) {
            children[e[0]].emplace_back(e[1]);
            children[e[1]].emplace_back(e[0]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = dfs(i, -1, children, k);
        return ans;
    }

    int dfs(int node, int parent, vector<vector<int>>& children, int k) {
        if (k < 0)
            return 0;
        int ans = 1;
        for (const int& child: children[node]) {
            if (child == parent)
                continue;
            ans += dfs(child, node, children, k - 1);
        }
        return ans;
    }
};
