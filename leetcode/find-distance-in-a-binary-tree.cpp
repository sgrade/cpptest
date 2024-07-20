// 1740. Find Distance in a Binary Tree
// https://leetcode.com/problems/find-distance-in-a-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 3: One pass (Based on Lowest Common Ancestor)
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
    int findDistance(TreeNode* root, int p, int q) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        if (p == q)
            return 0;
        this->p = p;
        this->q = q;
        return getDistance (root, 0);
    }

private:
    int p, q;
    int getDistance (TreeNode* node, int depth) {
        if (node == nullptr)
            return 0;
        if (node->val == p || node->val == q) {
            int left = getDistance (node->left, 1);
            int right = getDistance (node->right, 1);
            return (left > 0 || right > 0) ? max (left, right) : depth;
        }
        int left = getDistance (node->left, depth + 1);
        int right = getDistance (node->right, depth + 1);
        int ans = left + right;
        if (left != 0 && right != 0)
            ans -= 2depth;
        return ans;
    }
};
