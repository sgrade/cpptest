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


// Wrong Answer: 65 / 67 testcases passed
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->head = head;
        this->root = root;
        return dfs(head, root);
    }
private:
    ListNode* head;
    TreeNode* root;
    bool dfs(ListNode* list_node, TreeNode* tree_node) {
        if (tree_node == nullptr)
            return false;
        bool found = false;
        if (tree_node->val == list_node->val) {
            if (list_node->next == nullptr)
                return true;
            else {
                found =
                dfs(list_node->next, tree_node->left) ||
                dfs(list_node->next, tree_node->right);
            }
        }
        else if (tree_node->val == head->val) {
            found =
            dfs(head->next, tree_node->left) ||
            dfs(head->next, tree_node->right);
        }
        else {
            found =
            dfs(head, tree_node->left) ||
            dfs(head, tree_node->right);
        }
        return found;
    }
};
