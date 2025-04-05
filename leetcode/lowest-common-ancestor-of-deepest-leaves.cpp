// 1123. Lowest Common Ancestor of Deepest Leaves
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursion
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
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);

            return dfs(root).first;
        }
    private:
        pair<TreeNode*, int> dfs(TreeNode* root) {
            if (root == nullptr)
                return {root, 0};
            pair<TreeNode*, int> left = dfs(root->left), right = dfs(root->right);
            if (left.second > right.second)
                return {left.first, left.second + 1};
            if (right.second > left.second)
                return {right.first, right.second + 1};
            return {root, left.second + 1};
        }
    };
