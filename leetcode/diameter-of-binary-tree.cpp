// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int maxD = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxD;
    }
    
    int dfs(TreeNode* curNode) {
        
        if (curNode == nullptr) return 0;
        
        int left = dfs(curNode->left);
        int right = dfs(curNode->right);
        
        int curD = left + right;
        
        maxD = max(maxD, curD);
        
        return max(left, right) + 1;
    }
};
