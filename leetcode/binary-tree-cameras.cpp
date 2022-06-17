// 968. Binary Tree Cameras
// https://leetcode.com/problems/binary-tree-cameras/

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
    int ans;
    unordered_set<TreeNode*> covered;
    
    int minCameraCover(TreeNode* root) {
        covered.clear();
        covered.insert(nullptr);
        ans = 0;
        dfs(root, nullptr);
        return ans;
    }
    
    void dfs(TreeNode* cur, TreeNode* parent) {
        
        if (cur == nullptr) return;
        
        dfs(cur->left, cur);
        dfs(cur->right, cur);

        if (parent == nullptr && covered.find(cur) == covered.end() ||
            covered.find(cur->left) == covered.end() ||
            covered.find(cur->right) == covered.end()) {
                ++ans;
                covered.insert(parent);
                covered.insert(cur);
                covered.insert(cur->left);
                covered.insert(cur->right);
        }
    }
};
