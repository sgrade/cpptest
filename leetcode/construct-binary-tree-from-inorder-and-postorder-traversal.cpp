// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Recursion
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_idx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_idxes[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1);
    }
    
private:
    int postorder_idx;
    map<int, int> inorder_idxes;
    
    TreeNode* helper(const vector<int> &inorder, const vector<int> &postorder, const int left, const int right) {
        if (left > right) {
            return nullptr;
        }
        
        int root_val = postorder[postorder_idx];
        TreeNode* root = new TreeNode(root_val);
        
        int inorder_idx = inorder_idxes[root_val];
        
        --postorder_idx;
        
        root->right = helper(inorder, postorder, inorder_idx + 1, right);
        root->left = helper(inorder, postorder, left, inorder_idx - 1);
        
        return root;
    }
};
