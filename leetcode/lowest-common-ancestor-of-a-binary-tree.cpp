// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursive Approach

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

        Recurse(root, p, q);
        return ans;
    }
private:
    TreeNode* ans = nullptr;
    bool Recurse(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr)
            return false;
        int left = Recurse(node->left, p, q);
        int right = Recurse(node->right, p, q);
        int self = node == p || node == q;
        int score = left + right + self;
        if (score >= 2)
            ans = node;
        return score > 0;
    }
};
