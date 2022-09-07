// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {        
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* current) {
        if (current == nullptr) {
            return;
        }
        ans.emplace_back(current -> val);
        dfs(current -> left);
        dfs(current -> right);
    }
};
