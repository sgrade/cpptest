// 1367. Linked List in Binary Tree
// https://leetcode.com/problems/linked-list-in-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Based On Editorial's Approach 1: DFS
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        return dfs1(root, head);
    }
private:
    bool dfs1(TreeNode* tree_node, ListNode* head) {
        if (tree_node == nullptr)
            return false;
        if (dfs2(tree_node, head))
            return true;
        return dfs1(tree_node->left, head) || dfs1(tree_node->right, head);
    }
    bool dfs2(TreeNode* tree_node, ListNode* list_node) {
        if (list_node == nullptr)
            return true;
        if (tree_node == nullptr)
            return false;
        if (tree_node->val != list_node->val)
            return false;
        return dfs2(tree_node->left, list_node->next) || dfs2(tree_node->right, list_node->next);
    }
};
