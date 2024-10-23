// 2641. Cousins in Binary Tree II
// https://leetcode.com/problems/cousins-in-binary-tree-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Two Pass BFS

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        q.emplace(root);
        vector<int> level_sums;

        while (!q.empty()) {
            int level_sum = 0;
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            level_sums.emplace_back(level_sum);
        }

        q.emplace(root);
        int level = 1;
        root->val = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                int sum = 0;
                sum += node->left ? node->left->val : 0;
                sum += node->right ? node->right->val : 0;
                if (node->left) {
                    node->left->val = level_sums[level] - sum;
                    q.emplace(node->left);
                }
                if (node->right) {
                    node->right->val = level_sums[level] - sum;
                    q.emplace(node->right);
                }
            }
            ++level;
        }

        return root;
    }
};
