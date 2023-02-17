// 783. Minimum Distance Between BST Nodes
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    int minDiffInBST(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> st;
        st.emplace(root);
        TreeNode* node;
        while(!st.empty()) {
            node = st.top();
            st.pop();
            if (node == nullptr) continue;
            values.emplace_back(node->val);
            st.emplace(node->left);
            st.emplace(node->right);
        }
        sort (values.begin(), values.end());
        int ans = numeric_limits<int>::max();
        for (int i = 1; i < values.size(); ++i) {
            ans = min(ans, values[i] - values[i - 1]);
        }
        return ans;
    }
};
