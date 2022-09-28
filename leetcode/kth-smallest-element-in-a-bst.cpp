// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    priority_queue<int> max_heap;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return max_heap.top();
    }
    
    void dfs(TreeNode* node, const int k) {
        if (max_heap.size() == k) {
            if (node->val > max_heap.top()) {
                return;
            }
            max_heap.pop();
        }
        max_heap.emplace(node->val);
        if (node->left) {
            dfs(node->left, k);
        }
        if (node->right) {
            dfs(node->right, k);
        }
    }
};
