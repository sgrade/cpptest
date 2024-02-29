// 1609. Even Odd Tree
// https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        queue<TreeNode*> q;
        q.emplace(root);
        bool even_level = true;
        while (!q.empty()) {
            int prev = even_level ? 0 : 1e6 + 1;
            int nodes = q.size();
            while (nodes--) {
                TreeNode* node = q.front();
                q.pop();
                if (even_level) {
                    if (node->val % 2 == 0 || node->val <= prev)
                        return false;
                }
                else {
                    if (node->val % 2 == 1 || node->val >= prev)
                        return false;
                }
                prev = node->val;
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            even_level = !even_level;
        }
        return true;
    }
};
