// 988. Smallest String Starting From Leaf
// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
    string ans = "";
    void dfs (TreeNode* node, string current_ans) {
        current_ans = char('a' + node->val) + current_ans;
        if (node->left)
            dfs(node->left, current_ans);
        if (node->right)
            dfs(node->right, current_ans);
        if (node->left == nullptr && node->right == nullptr)
            ans = ans.empty() ? current_ans : min(ans, current_ans);
    }
};
