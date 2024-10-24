// 951. Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursion (Top-down Traversal)

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2-> val)
            return false;

        bool swap = flipEquiv(root1->left, root2->right) &&
            flipEquiv(root1->right, root2->left);
        bool no_swap = flipEquiv(root1->left, root2->left) &&
            flipEquiv(root1->right, root2->right);
        return swap || no_swap;
    }
};
