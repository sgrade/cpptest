// 1038. Binary Search Tree to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    TreeNode* bstToGst(TreeNode* root) {
        vals.resize(101, -1);
        dfs(root);
        int sum = 0;
        for (int i = 100; i >= 0; --i) {
            if (vals[i] == 0) {
                sum += i;
                vals[i] = sum;
            }
        }
        dfs_replace(root);
        return root;
    }
private:
    vector<int> vals;
    void dfs (TreeNode* node) {
        if (node->right)
            dfs(node->right);
        vals[node->val] = 0;
        if (node->left)
            dfs(node->left);
    }
    void dfs_replace (TreeNode* node) {
        if (node == nullptr)
            return;
        node->val = vals[node->val];
        dfs_replace (node->right);
        dfs_replace (node->left);
    }
};
