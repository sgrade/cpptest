// 889. Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Divide and Conquer
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        n = preorder.size();
        return getTree (0, n - 1, 0, preorder, postorder);
    }

private:
    int n;

    TreeNode* getTree (int pre_start, int pre_end, int post_start, vector<int>& preorder, vector<int>& postorder) {
        if (pre_start > pre_end)
            return nullptr;
        if (pre_start == pre_end)
            return new TreeNode(preorder[pre_start]);
        int left_root = preorder[pre_start + 1];
        int nodes = 1;
        while (postorder[post_start + nodes - 1] != left_root)
            ++nodes;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        root->left = getTree (pre_start + 1, pre_start + nodes, post_start, preorder, postorder);
        root->right = getTree (pre_start + nodes + 1, pre_end, post_start + nodes, preorder, postorder);
        return root;
    }
};
