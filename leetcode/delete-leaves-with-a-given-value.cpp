// 1325. Delete Leaves With a Given Value
// https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        this->target = target;
        return dfs(root) ? nullptr : root;
    }

private:
    int target;
    bool dfs (TreeNode* node) {
        if (node == nullptr)
            return false;
        bool left = false, right = false;
        if (node->left)
            left = dfs(node->left);
        if (node->right)
            right = dfs(node->right);
        if (left)
            node->left = nullptr;
        if (right)
            node->right = nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == target)
                return true;
        }
        return false;
    }
};
