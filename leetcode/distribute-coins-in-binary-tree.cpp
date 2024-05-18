// 979. Distribute Coins in Binary Tree
// https://leetcode.com/problems/distribute-coins-in-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Depth-First Search

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
    int distributeCoins(TreeNode* root) {
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
        ans += abs(left) + abs(right);
        int balance = node->val -1 + left + right;
        return balance;
    }
};
