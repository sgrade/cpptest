// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        dfs (root);
        return ans;
    }
private:
    int ans = 0;
    void dfs (TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        dfs (node->left);
        ++ans;
        dfs (node->right);
    }
};
