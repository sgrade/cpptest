// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;
        Traverse(vp, root, p);
        Traverse(vq, root, q);
        TreeNode* ans = root;
        for (int i = 1; i < min(vp.size(), vq.size()); ++i) {
            if (vp[i] == vq[i]) ans = vp[i];
            else break;
        }
        return ans;
    }
private:
    void Traverse(vector<TreeNode*> &v, TreeNode* node, TreeNode* target) {
        v.emplace_back(node);
        if (node->val == target->val) {
            return;
        }
        if (node->val > target->val) {
            Traverse(v, node->left, target);
        }
        else {
            Traverse(v, node->right, target);
        }
    }
};
