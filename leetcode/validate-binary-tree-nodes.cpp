// 1361. Validate Binary Tree Nodes
// https://leetcode.com/problems/validate-binary-tree-nodes/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search (DFS)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        this->n = n;
        int root = FindRoot(leftChild, rightChild);
        if (root == -1)
            return false;
        
        vector<bool> visited(n);
        visited[root] = true;
        stack<int> dfs;
        dfs.emplace(root);

        while(!dfs.empty()) {
            int node = dfs.top();
            dfs.pop();
            vector<int> children = {leftChild[node], rightChild[node]};
            for (const int& child: children) {
                if (child != -1) {
                    if (visited[child])
                        return false;
                    dfs.emplace(child);
                    visited[child] = true;
                }
            }
        }

        return find(visited.begin(), visited.end(), false) == visited.end();
    }

private:
    int n;
    int FindRoot(vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        for (int i = 0; i < n; ++i)
            if (children.find(i) == children.end())
                return i;
        return -1;
    }
};
