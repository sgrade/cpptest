// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (IsIdentical(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool IsIdentical(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr || node2 == nullptr)
            return node1 == nullptr && node2 == nullptr;
        return node1->val == node2->val &&
            IsIdentical(node1->left, node2->left) &&
            IsIdentical(node1->right, node2->right);
    }
};
