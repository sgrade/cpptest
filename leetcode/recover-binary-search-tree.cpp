// 99. Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Recursive Inorder Traversal
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
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(a->val, b->val);
    }
private:
    TreeNode *a = nullptr;
    TreeNode *b = nullptr;
    TreeNode *prev = nullptr;
    void dfs (TreeNode *current) {
        if (current == nullptr) {
            return;
        }
        dfs(current->left);
        if (prev != nullptr && current->val < prev->val) {
            b = current;
            if (a == nullptr) {
                a = prev;
            }
            else {
                return;
            }
        }
        prev = current;
        dfs(current->right);
    }
};
