// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

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


// Based on Editorial's Approach 2: Breadth-First Search Right to Left
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* node;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->right)
                q.emplace(node->right);
            if (node->left)
                q.emplace(node->left);
        }
        return node->val;
    }
};
