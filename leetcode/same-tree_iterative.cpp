// 100. Same Tree
// https://leetcode.com/problems/same-tree/

// Based on Leetcode's Approach 2: Iteration


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq, qq;
        pq.emplace(p);
        qq.emplace(q);
        while(!pq.empty()) {
            p = pq.front();
            pq.pop();
            q = qq.front();
            qq.pop();
            if (!CompareNodes(p,q)) {
                return false;
            }
            if (p != nullptr) {
                if (!CompareNodes(p->left, q->left)) {
                    return false;
                }
                if (p->left != nullptr) {
                    pq.emplace(p->left);
                    qq.emplace(q->left);
                }
                if (!CompareNodes(p->right, q->right)) {
                    return false;
                }
                if (p->right != nullptr) {
                    pq.emplace(p->right);
                    qq.emplace(q->right);
                }
            }
        }
        return true;
    }
private:
    bool CompareNodes(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;
        return true;
    }
};
