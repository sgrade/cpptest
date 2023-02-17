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
        int ans = numeric_limits<int>::max();
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while (node != nullptr || !st.empty()) {
            while (node != nullptr) {
                st.emplace(node);
                node = node->left;
            }
            node = st.top();
            if (prev != nullptr) ans = min(ans, node->val - prev->val);
            prev = node;

            st.pop();
            node = node->right;
        }
        return ans;
    }
};
