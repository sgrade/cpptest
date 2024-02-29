// 1973. Count Nodes Equal to Sum of Descendants
// https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/

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
    int equalToDescendants(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    long dfs (TreeNode* node) {
        if (node == nullptr)
            return 0LL;
        long left = dfs(node->left);
        long right = dfs(node->right);
        if (node->val == left + right)
            ++ans;
        return node->val + left + right;
    }
};
