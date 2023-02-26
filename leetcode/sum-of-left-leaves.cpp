// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        TreeNode* node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node == nullptr) continue;
            if (node->left) {
               q.emplace(node->left);
               if (node->left->left == nullptr && node->left->right == nullptr) ans += node->left->val; 
            }
            if (node->right) q.emplace(node->right);
        }
        return ans;
    }
};
