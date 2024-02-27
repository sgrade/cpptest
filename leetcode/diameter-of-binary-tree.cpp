// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {;
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
