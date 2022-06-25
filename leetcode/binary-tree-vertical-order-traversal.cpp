// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        unordered_map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q; // Node and its column
        int column = 0;
        q.push({root, column});
        
        int min_column = 0, max_column = 0;
        
        while (!q.empty()) {
            pair<TreeNode* , int> p = q.front();
            q.pop();
            root = p.first;
            column = p.second;
            
            if (root == nullptr) {
                continue;
            }
            
            if (columns.find(column) == columns.end()) {
                columns[column] = {};
            }
            columns[column].push_back(root -> val);
            min_column = min(min_column, column);
            max_column = max(max_column, column);

            q.push({root -> left, column - 1});
            q.push({root -> right, column + 1});
        }
        
        for (int i = min_column; i < max_column + 1; ++i) {
            ans.push_back(columns[i]);
        }
        
        return ans;
    }
};
