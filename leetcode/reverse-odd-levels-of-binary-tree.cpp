// 2415. Reverse Odd Levels of Binary Tree
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (!root)
            return nullptr;

        queue<TreeNode*> q;
        q.emplace(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> nodes(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                nodes[i] = node;
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            if (level % 2 == 1) {
                int left = 0, right = n - 1;
                while (left < right) {
                    int val = nodes[left]->val;
                    nodes[left]->val = nodes[right]->val;
                    nodes[right]->val = val;
                    ++left;
                    --right;
                }
            }
            ++level;
        }

        return root;
    }
};
