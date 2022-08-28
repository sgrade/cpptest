// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return abs(height(root->left) - height(root->right)) < 2 && 
                  isBalanced(root->left) &&
                  isBalanced(root->right);
    }
    
    int height(TreeNode* cur) {
        if (cur == nullptr) {
            return -1;
        }
        return 1 + max(height(cur->left), height(cur->right));
    }
};