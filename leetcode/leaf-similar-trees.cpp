// 872. Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        traverse(leaves1, root1);
        traverse(leaves2, root2);
        return (leaves1 == leaves2);
    }
private:
    void traverse(vector<int>&leaves, TreeNode* node) {
        if (node == nullptr)
            return;
        if (node->left)
            traverse(leaves, node->left);
        if (node->right)
            traverse(leaves, node->right);
        if (node->left == nullptr && node->right == nullptr)
            leaves.emplace_back(node->val);
    }
};
