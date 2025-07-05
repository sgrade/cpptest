// 333. Largest BST Subtree
// https://leetcode.com/problems/largest-bst-subtree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: Post-Order Traversal

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Vals {
    public:
        int mx, mn, size;
        Vals(int mn, int mx, int size) : mn(mn), mx(mx), size(size) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        return dfs(root).size;
    }
private:
    Vals dfs(TreeNode* node) {
        // int mx = numeric_limits<int>::min(), mn = numeric_limits<int>::max();
        if (node == nullptr)
            return Vals(INT_MAX, INT_MIN, 0);
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left.mx < node->val && node->val < right.mn) {
            int mx = max(node->val, right.mx);
            int mn = min(node->val, left.mn);
            return Vals(mn, mx, left.size + right.size + 1);
        }
        return Vals(INT_MIN, INT_MAX, max(left.size, right.size));
    }
};
