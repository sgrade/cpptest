// 652. Find Duplicate Subtrees
// https://leetcode.com/problems/find-duplicate-subtrees/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's A String Representation Approach

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        Traverse(root);
        return ans;
    }
private:
    unordered_map<string, int> counter;
    vector<TreeNode*> ans;
    string Traverse (TreeNode* node) {
        if (node == nullptr) 
            return "";
        string representation = 
            "(" + Traverse(node->left) + ")" + 
            to_string(node->val) + 
            "(" + Traverse(node->right) + ")";
        ++counter[representation];
        if (counter[representation] == 2)
            ans.emplace_back(node);
        return representation;
    }
};
