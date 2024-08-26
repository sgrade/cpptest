// 590. N-ary Tree Postorder Traversal
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
private:
    vector<int> ans;
    void dfs(const Node* node) {
        if (node == nullptr)
            return;
        for (const Node* child: node->children)
            dfs(child);
        ans.emplace_back(node->val);
    }
};
