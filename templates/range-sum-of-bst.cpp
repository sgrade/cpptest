// 938. Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (root == nullptr)
            return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int v = node->val;
            if (v >= low && v <= high)
                ans += v;
            if (node->left)
                q.emplace(node->left);
            if (node->right)
                q.emplace(node->right);
        }
        return ans;
    }
};
