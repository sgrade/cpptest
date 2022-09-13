// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int preorder_idx;
    unordered_map<int, int> inorder_idx;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_idx = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_idx[inorder[i]] = i;
        }
        
        return buildSubTree (preorder, 0, preorder.size() - 1);
    }
    
    TreeNode* buildSubTree (vector<int> &preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int root_val = preorder[preorder_idx++];
        TreeNode* root = new TreeNode(root_val);
        
        root->left = buildSubTree (preorder, left, inorder_idx[root_val] - 1);
        root->right = buildSubTree (preorder, inorder_idx[root_val] + 1, right);
        
        return root;
    }
};
