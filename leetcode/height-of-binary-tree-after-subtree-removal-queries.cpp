// 2458. Height of Binary Tree After Subtree Removal Queries
// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Left and Right Traversal

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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        max_heights.resize(1e5 + 1);

        traverse_left (root, 0);
        cur_max = 0;
        traverse_right (root, 0);

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; ++i)
            ans[i] = max_heights[queries[i]];
        return ans;
    }

private:
    vector<int> max_heights;
    int cur_max = 0;

    void traverse_left (TreeNode* node, int cur_height) {
        if (node == nullptr)
            return;
        max_heights[node->val] = cur_max;
        cur_max = max (cur_max, cur_height);
        traverse_left (node->left, cur_height + 1);
        traverse_left (node->right, cur_height + 1);
    }

    void traverse_right (TreeNode* node, int cur_height) {
        if (node == nullptr)
            return;
        max_heights[node->val] = 
            max(max_heights[node->val], cur_max);
        cur_max = max(cur_max, cur_height);
        traverse_right (node->right, cur_height + 1);
        traverse_right (node->left, cur_height + 1);
    }
};
