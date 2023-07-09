// 559. Maximum Depth of N-ary Tree
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        ans = 0;
        Traverse(root, 0);
        return ans;
    }

private:
    int ans;
    void Traverse (Node* node, int parent_depth) {
        ans = max (ans, parent_depth + 1);
        for (Node* child: node->children)
            Traverse (child, parent_depth + 1);
    }
};
