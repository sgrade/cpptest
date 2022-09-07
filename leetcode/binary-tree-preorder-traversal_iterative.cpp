// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans; 
        if (root == nullptr) 
            return ans;
        
        stack<TreeNode*> st;
        st.emplace(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            ans.emplace_back(root->val);
            if (root->right != nullptr)
                st.emplace(root->right);
            if (root->left != nullptr)
                st.emplace(root->left);
        }
        
        return ans;
    }
};
