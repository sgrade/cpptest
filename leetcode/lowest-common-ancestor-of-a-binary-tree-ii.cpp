// 1644. Lowest Common Ancestor of a Binary Tree II
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth First Search - Modify LCA Solution
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        ans = LCA(root, p, q);
        if (ans == p)
            return dfs(p, q) ? p : nullptr;
        else if (ans == q)
            return dfs(q, p) ? q : nullptr;
        return ans;
    }

private:
    TreeNode* ans;
    TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr || node == p || node == q)
            return node;
        TreeNode* left = LCA(node->left, p, q);
        TreeNode* right = LCA(node->right, p, q);
        if (left && right)
            return node;
        else if (left)
            return left;
        else
            return right;
    }

    bool dfs(TreeNode* node, TreeNode* target) {
        if (node == target)
            return true;
        if (node == nullptr)
            return false;
        bool current = dfs(node->left, target) || dfs(node->right, target);
        return current;
    }
};
