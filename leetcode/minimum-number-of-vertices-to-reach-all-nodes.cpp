// 1557. Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: In-Degree Count
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incoming_edge_exists(n);
        for (const vector<int>& edge: edges) {
            incoming_edge_exists[edge[1]] = true;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!incoming_edge_exists[i])
                ans.emplace_back(i);
        }
        return ans;
    }
};
