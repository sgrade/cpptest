// 116. Populating Next Right Pointers in Each Node
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        root->next = nullptr;
        if (root->left) {
            explore(root->left, root, true);
            explore(root->right, root, false);
        }
        return root;
    }
    
    void explore(Node* current, Node* parent, bool i_am_left) {
        if (i_am_left) {
            current->next = parent->right;
        }
        else {
            if (parent->next) {
                current->next = parent->next->left;
            }
            else {
                current->next = nullptr;
            }
        }
        if (current->left) {
            explore(current->left, current, true);
            explore(current->right, current, false);
        }
    }
};
