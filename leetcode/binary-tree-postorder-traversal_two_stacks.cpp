// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) 
            return ans;
        
        stack<TreeNode*> st1, st2;
        st1.emplace(root);
        while(!st1.empty()) {
            root = st1.top();
            st2.push(root);
            st1.pop();
            if (root->left) 
                st1.push(root->left);
            if (root->right) 
                st1.push(root->right);
        }
        
        while(!st2.empty()) {
            ans.emplace_back(st2.top()->val);
            st2.pop();
        }
        
        return ans;
    }
};
