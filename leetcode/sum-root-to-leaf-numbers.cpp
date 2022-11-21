// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, 0);
        return ans;
    }
    
private:
    void dfs(TreeNode* node, int &ans, int current_sum) {
        if (node == nullptr) {
            return;
        }
        
        current_sum *= 10;
        current_sum += node->val;
        
        if (node->left == nullptr && node->right == nullptr) {
            ans += current_sum;
            return;
        }
        
        dfs(node->left, ans, current_sum);
        dfs(node->right, ans, current_sum);
    }
};
