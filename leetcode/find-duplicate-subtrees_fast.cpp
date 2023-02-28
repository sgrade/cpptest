// 652. Find Duplicate Subtrees
// https://leetcode.com/problems/find-duplicate-subtrees/

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


// Based on Leetcode's A String Representation Approach
// Optimized with ideas from a top-performing submission
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        Traverse(root);
        return ans;
    }
private:
    unordered_map<string, pair<int, int>> counter;
    vector<TreeNode*> ans;
    int id = 0;
    string Traverse (TreeNode* node) {
        if (node == nullptr) 
            return "0";
        string representation = 
            Traverse(node->left) + "," + 
            to_string(node->val) + "," + 
            Traverse(node->right);
        if (counter.find(representation) == counter.end()) 
            counter[representation] = {++id, 1};
        else {
            ++counter[representation].second;
            if (counter[representation].second == 2)
                ans.emplace_back(node);
        }
        return to_string(counter[representation].first);
    }
};
