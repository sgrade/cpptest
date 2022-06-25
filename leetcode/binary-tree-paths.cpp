// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs (root, to_string(root -> val), ans);
        return ans;
    }
    void dfs(TreeNode* current_node, string current_path, vector<string> &ans) {
        if (current_node == nullptr) return;
        if (current_node -> left == nullptr && current_node -> right == nullptr) {
            ans.push_back(current_path);
            return;
        }
        if (current_node -> left) {
            dfs (current_node -> left, 
                 current_path + "->" + to_string(current_node -> left -> val), 
                 ans);
        }
        if (current_node -> right) {   
            dfs (current_node -> right, 
                 current_path + "->" + to_string(current_node -> right -> val), 
                 ans);
        }
    }
};
