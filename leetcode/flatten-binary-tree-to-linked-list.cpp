// 114. Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        dfs(root);
    }
    
    TreeNode* dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return nullptr;
        }
        
        if (cur->left == nullptr && cur->right == nullptr) {
            return cur;
        }
        
        TreeNode* left_tail = dfs(cur->left);
        TreeNode* right_tail = dfs(cur->right);
        
        if (left_tail != nullptr) {
            left_tail->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        
        return right_tail == nullptr ? left_tail : right_tail;
    }
};
