// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: BFS without Sorting
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        
        unordered_map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q;
        int column = 0;
        q.emplace(root, column);
        int min_col = 0, max_col = 0;

        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            columns[col].emplace_back(node->val);
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            if (node->left)
                q.emplace(node->left, col - 1);
            if (node->right)
                q.emplace(node->right, col + 1);
        }

        for (int i = min_col; i < max_col + 1; ++i)
            ans.emplace_back(columns[i]);
        
        return ans;
    }
};
