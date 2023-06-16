// 501. Find Mode in Binary Search Tree
// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        dfs(root);
        return ans;
    }
private:
    int max_cnt = 0; 
    int current_cnt = 0;
    TreeNode* prev = nullptr;
    void dfs (TreeNode* node) {
        if (node == nullptr) return;
        dfs (node->left);
        if (prev && prev->val == node->val)
            ++current_cnt;
        else
            current_cnt = 1;

        if (current_cnt > max_cnt) {
            max_cnt = current_cnt;
            ans.clear();
            ans.push_back(node->val);
        }
        else if (current_cnt == max_cnt)
            ans.push_back(node->val);
        prev = node;
        dfs (node->right);
    }
};
