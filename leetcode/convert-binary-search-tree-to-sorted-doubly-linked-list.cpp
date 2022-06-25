// 426. Convert Binary Search Tree to Sorted Doubly Linked List
// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

#include <bits/stdc++.h>

using namespace std;


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

class Solution {
public:
    Node* first = nullptr;
    Node* last = nullptr;
        
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        first->left = last;
        last->right = first;
        return first;
    }
    
    void dfs(Node* current) {
        if (current == nullptr) {
            return;
        }
        dfs(current -> left);
        
        // DFS Inorder
        if (last) {
            current->left = last;
            last->right = current;
        }
        else {
            first = current;
        }
        last = current;
        
        dfs(current -> right);
    }
};
