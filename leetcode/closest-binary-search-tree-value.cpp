// 270. Closest Binary Search Tree Value
// https://leetcode.com/problems/closest-binary-search-tree-value/

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
    int closestValue(TreeNode* root, double target) {
        float d = numeric_limits<float>::max(), current_d;
        int ans = root->val;
        stack<TreeNode*> st;
        st.emplace(root);
        TreeNode* node;
        while (!st.empty()) {
            node = st.top();
            st.pop();
            current_d = abs(target - node->val);
            if (current_d < d) {
                ans = node->val;
                d = current_d;
            }
            if (node->left) st.emplace(node->left);
            if (node->right) st.emplace(node->right);
        }
        return ans;
    }
};
