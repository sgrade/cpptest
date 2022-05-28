// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int mx = 0;
    
    int maxPathSum(TreeNode* root) {
        mx = root->val;
        dfs(root);
        return mx;
    }
    
    int dfs(TreeNode* cur) {
        if (cur == nullptr) return 0;
        
        int leftSum = max(dfs(cur->left), 0);
        int rightSum = max(dfs(cur->right), 0);
        int curSum = cur->val + leftSum + rightSum;
        
        mx = max(mx, curSum);
        
        return cur->val + max(leftSum, rightSum);
    }
};


int main() {



    return 0;
}
