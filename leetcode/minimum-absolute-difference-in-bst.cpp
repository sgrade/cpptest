// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }

private:
    TreeNode* prev = nullptr;
    int ans = numeric_limits<int>::max();
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        if (prev)
            ans = min(ans, node->val - prev->val);
        prev = node;
        inorder(node->right);
    }
};
