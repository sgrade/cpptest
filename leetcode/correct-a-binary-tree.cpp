// 1660. Correct a Binary Tree
// https://leetcode.com/problems/correct-a-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// My own solution is very similar to Editorial's Approach 1: Breadth-First Search

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
    TreeNode* correctBinaryTree(TreeNode* root) {
        // <node, parent>
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(root, nullptr);
        while (!q.empty()) {
            unordered_set<TreeNode*> seen;
            while (!q.empty()) {
                int i = q.size();
                while (i--){
                    auto [node, parent] = q.front();
                    q.pop();
                    if (seen.find(node->right) != seen.end()) {
                        if (parent->left == node)
                            parent->left = nullptr;
                        else
                            parent->right = nullptr;
                        return root;
                    }
                    seen.emplace(node);
                    if (node->right)
                        q.emplace(node->right, node);
                    if (node->left)
                        q.emplace(node->left, node);
                }
            }
        }
        return root;
    }
};
