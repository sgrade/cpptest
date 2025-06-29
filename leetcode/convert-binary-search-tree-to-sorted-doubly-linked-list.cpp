// 426. Convert Binary Search Tree to Sorted Doubly Linked List
// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Recursion

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;

    Node* treeToDoublyList(Node* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (root == nullptr)
            return nullptr;
        dfs(root);
        first->left = last;
        last->right = first;
        return first;
    }

private:
    void dfs(Node* node) {
        if (node == nullptr)
            return;
        dfs(node->left);
        if (last != nullptr) {
            last->right = node;
            node->left = last;
        }
        else {
            first = node;
        }
        last = node;
        dfs(node->right);
    }
};
