// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

#include <bits/stdc++.h>

using namespace std;


// Based on the Editorial's Approach 2: Using BST properties

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        TreeNode* ans = nullptr;
        while (root != nullptr) {
            if (p->val >= root->val)
                root = root->right;
            else {
                ans = root;
                root = root->left;
            }
        }
        return ans;
    }
};
