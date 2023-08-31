// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        // BFS
        // level, node
        queue<pair<int, TreeNode*>> q;
        q.emplace(0, root);
        
        vector<vector<int>> levels;
        while (!q.empty()) {
            auto& [level, node] = q.front();
            if (levels.size() == level)
                levels.emplace_back(vector<int>{node->val});
            else
                levels[level].emplace_back(node->val);
            if (node->left)
                q.emplace(level + 1, node->left);
            if (node->right)
                q.emplace(level + 1, node->right);
            q.pop();
        }

        for (const vector<int>& level: levels) {
            ans.emplace_back(accumulate(level.begin(), level.end(), 0.0) / level.size());
        }
        return ans;
    }
};
