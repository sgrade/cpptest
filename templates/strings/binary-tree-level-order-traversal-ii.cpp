// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void dfs(TreeNode* node, vector<vector<int>> &ans, int level) {
        if (node == nullptr) {
            return;
        }
        if (level == ans.size()) {
            ans.emplace_back(vector<int>{});
        }
        ans[level].emplace_back(node->val);
        dfs(node->left, ans, level + 1);
        dfs(node->right, ans, level + 1);
    }
};
