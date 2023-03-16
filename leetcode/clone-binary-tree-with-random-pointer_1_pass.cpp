// 1485. Clone Binary Tree With Random Pointer
// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/

#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;
    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
};


class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* root_copy = MakeNewNode(root);
        return root_copy;
    }
private:
    NodeCopy* MakeNewNode (Node* node) {
        if (node == nullptr) 
            return nullptr;
        if (old_to_new.find(node) != old_to_new.end())
            return old_to_new[node];
        NodeCopy* node_copy = new NodeCopy(node->val);
        old_to_new[node] = node_copy;
        node_copy->left = MakeNewNode(node->left);
        node_copy->right = MakeNewNode(node->right);
        node_copy->random = MakeNewNode(node->random);
        return node_copy;
    }

    unordered_map<Node*, NodeCopy*> old_to_new;
};
