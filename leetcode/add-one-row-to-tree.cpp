// 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        --depth;
        if (depth == 0) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }

        queue<TreeNode*> q;
        q.emplace(root);
        while (--depth) {
            int len = q.size();
            while (len--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
        }

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            TreeNode* old_left = node->left;
            TreeNode* old_right = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = old_left;
            node->right->right = old_right;
        }

        return root;
    }
};
