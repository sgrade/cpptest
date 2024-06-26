// 1382. Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree/

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
    TreeNode* balanceBST(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            values.emplace_back(node->val);
            if (node->left)
                q.emplace(node->left);
            if (node->right)
                q.emplace(node->right);
        }
        sort(values.begin(), values.end());

        TreeNode* new_root = new TreeNode();
        TreeNode* prev = new_root;
        dfs (0, values.size() - 1, prev);
        return new_root;
    }

private:
        vector<int> values;
        TreeNode* ans;
        void dfs (int left, int right, TreeNode* node) {
            int mid = left + (right - left + 1) / 2;
            node->val = values[mid];
            if (left == right)
                return;
            if (mid != right) {
                TreeNode* right_node = new TreeNode();
                node->right = right_node;
                dfs (mid + 1, right, right_node);
            }
            if (mid != left) {
                TreeNode* left_node = new TreeNode();
                node->left = left_node;
                dfs (left, mid - 1, left_node);
            }
        }
};
