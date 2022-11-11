// 95. Unique Binary Search Trees II
// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Recursion

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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if (n == 0) {
            return ans;
        }
        return GenerateTrees (1, n);
    }

private:
    vector<TreeNode*> GenerateTrees (int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.emplace_back(nullptr);
            return ans;
        }
        
        for (int root = start; root <= end; ++root) {
            vector<TreeNode*> left_trees = GenerateTrees (start, root - 1);
            vector<TreeNode*> right_trees = GenerateTrees(root + 1, end);
            for (TreeNode* l: left_trees) {
                for (TreeNode* r: right_trees) {
                    TreeNode* current_tree = new TreeNode(root);
                    current_tree->left = l;
                    current_tree->right = r;
                    ans.emplace_back(current_tree);
                }
            }
        }
        
        return ans;
    }
};
