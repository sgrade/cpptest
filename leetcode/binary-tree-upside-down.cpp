// 156. Binary Tree Upside Down
// https://leetcode.com/problems/binary-tree-upside-down/

#include <bits/stdc++.h>

using namespace std;


// Based on https://leetcode.com/problems/binary-tree-upside-down/discuss/2691938/Strait-code-from-the-description-C%2B%2B

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        return dfs(root, nullptr, nullptr);
    }
private:
    TreeNode* dfs(TreeNode* new_root, TreeNode* new_left, TreeNode* new_right) {
        TreeNode *old_left = new_root->left, *old_right = new_root->right;
        new_root->left = new_left;
        new_root->right = new_right;
        if (old_left) {
            return dfs(old_left, old_right, new_root);
        }
        return new_root;
    }
};
