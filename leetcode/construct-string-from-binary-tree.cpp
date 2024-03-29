// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    string ans;
    void dfs(TreeNode* node) {
        if (node == nullptr)
            return;
        ans += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
            return;
        ans += '(';
        dfs(node->left);
        ans += ')';
        if (node->right != nullptr) {
            ans += '(';
            dfs(node->right);
            ans += ')';
        }
    }
};
