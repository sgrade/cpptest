// 250. Count Univalue Subtrees
// https://leetcode.com/problems/count-univalue-subtrees/

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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int tmp = PostOrderTraversal(root);
        return ans;
    }
private:
    int ans = 0;
    int PostOrderTraversal(TreeNode* node) {
        int left = 1001, right = 1001;
        if (node->left) {
            left = PostOrderTraversal(node->left);
        }
        if (node->right) {
            right = PostOrderTraversal(node->right);
        }
        if ((left == 1001 || left == node->val) && (right == 1001 || right == node->val)) {
            ++ans;
            return node->val;
        }
        return -1001;
    }
};
