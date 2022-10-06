// 285. Inorder Successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/
// Based on Leetcode's Approach 1: Without using BST properties

#include <bits/stdc++.h>

using namespace std;


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
        
        // Left child exists
        if (p->right != nullptr) {
            TreeNode* leftmost = p->right;
            while (leftmost->left != nullptr) {
                leftmost = leftmost->left;
            }
            ans = leftmost;
        }
        
        // Left child doesn't exist, so ans is one of the ancestors
        else {
            FindInorderAncestor(root, p);
        }
        
        return ans;
    }

private:
    TreeNode* prev = nullptr;
    TreeNode* ans = nullptr;
    
    void FindInorderAncestor(TreeNode* node, TreeNode* p) {
        if (node == nullptr) {
            return;
        }
        
        FindInorderAncestor(node->left, p);
        
        if (prev == p && ans == nullptr) {
            ans = node;
            return;
        }
        
        prev = node;
        
        FindInorderAncestor(node->right, p);
    }
};
