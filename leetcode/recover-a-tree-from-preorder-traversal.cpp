// 1028. Recover a Tree From Preorder Traversal
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Iterative Approach with Stack (Single Pass)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                ++depth;
                ++i;
            }

            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                ++i;
            }

            TreeNode* node = new TreeNode(val);
            
            while (st.size() > depth)
                st.pop();

            if (!st.empty()) {
                if (st.top()->left == nullptr)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }

            st.emplace(node);
        }

        while (st.size() > 1)
            st.pop();
        
        return st.top();
    }
};
