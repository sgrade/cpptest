// 563. Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/

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
    int findTilt(TreeNode* root) {
        postorder(root);
        return ans;
    }
private:
    int ans = 0;
    int postorder(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left = postorder(node->left);
        int right = postorder(node->right);
        ans += abs(left - right);
        return left + right + node->val;
    }
};
