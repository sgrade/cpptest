// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
private:
    int ans = 0;
    void dfs (TreeNode* node, int num) {
        if (node->left == nullptr && node->right == nullptr) {
            ans += num;
            return;
        }
        num *= 10;
        if (node->left)
            dfs(node->left, num + node->left->val);
        if (node->right)
            dfs(node->right, num + node->right->val);
    }
};
