// 797. All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Backtracking
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        target = n - 1;
        vector<int> path{0};
        
        backtrack(0, path, graph);
        return ans;
    }
private:
    int target;
    vector<vector<int>> ans;
    void backtrack(int current_node, vector<int>& path, vector<vector<int>>& graph) {
        if (current_node == target) {
            ans.emplace_back(path);
            return;
        }
        for (const int& neighbor: graph[current_node]) {
            path.emplace_back(neighbor);
            backtrack(neighbor, path, graph);
            path.pop_back();
        }
    }
};
