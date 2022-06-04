// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
private:
    vector<int> ans;
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* cur) {
        if (cur != nullptr) {
            dfs(cur->left);
            ans.push_back(cur->val);
            dfs(cur->right);
        }
    }
};
