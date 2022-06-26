// 173. Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

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

class BSTIterator {
public:
    int index;
    vector<int> tree;
    int n;
    
    BSTIterator(TreeNode* root) {
        tree.clear();
        index = -1;
        dfs(root);
        n = tree.size();
    }
    
    int next() {
        return tree[++index];
    }
    
    bool hasNext() {
        return index + 1 < n;
    }
    
    void dfs(TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        dfs(cur -> left);
        tree.emplace_back(cur -> val);
        dfs(cur -> right);
    }
};

/**
Your BSTIterator object will be instantiated and called as such:
BSTIterator* obj = new BSTIterator(root);
int param_1 = obj->next();
bool param_2 = obj->hasNext();
 */
