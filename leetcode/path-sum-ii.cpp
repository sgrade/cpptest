// 113. Path Sum II
// https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int current_sum = 0;
        DfsPreorder(root, targetSum, ans, current_sum, path);
        return ans;
    }
    
private:
    void DfsPreorder(TreeNode* node, const int &targetSum, vector<vector<int>> &ans, int &current_sum, vector<int> &path) {
        if (node == nullptr) {
            return;
        }
        
        current_sum += node->val;
        path.emplace_back(node->val);
        
        if (node->left == nullptr && node->right == nullptr && current_sum == targetSum) {
            ans.emplace_back(path);
        }
        
        DfsPreorder(node->left, targetSum, ans, current_sum, path);
        DfsPreorder(node->right, targetSum, ans, current_sum, path);
        
        current_sum -= node->val;
        path.pop_back();
    }
};
