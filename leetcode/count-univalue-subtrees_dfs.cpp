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
        if(root == nullptr) {
            return 0;
        }
        IsValueSame(root, root->val);
        return ans;
    }
private:
    int ans = 0;
    bool IsValueSame(TreeNode* node, int parent_value) {
        if (node == nullptr) {
            return true;
        }
        bool left = IsValueSame(node->left, node->val);
        bool right = IsValueSame(node->right, node->val);
        bool subtrees_valid = left && right; 
        if (subtrees_valid) {
            ++ans;
        }
        return subtrees_valid && node->val == parent_value;
    }
};
