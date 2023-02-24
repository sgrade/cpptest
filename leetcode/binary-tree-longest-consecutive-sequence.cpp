// 298. Binary Tree Longest Consecutive Sequence
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    int longestConsecutive(TreeNode* root) {
        Traversal(root, root->val, 1);
        return ans;
    }
private:
    int ans = 1;
    void Traversal(TreeNode* node, int prev, int current_ans) {
        current_ans = prev + 1 == node->val ? current_ans + 1 : 1;
        ans = max(ans, current_ans);
        if (node->left) Traversal(node->left, node->val, current_ans);
        if (node->right)Traversal(node->right, node->val, current_ans);
    }
};
