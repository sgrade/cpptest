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
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<pair<int, int>> count_to_value;
        for (const auto& [val, cnt]: counter){
            count_to_value.emplace_back(cnt, val);
        }
        sort(count_to_value.begin(), count_to_value.end(), greater<pair<int, int>>());

        vector<int> ans;
        int count = count_to_value.front().first;
        for (const auto& [cnt, val]: count_to_value) {
            if (cnt != count) break;
            ans.emplace_back(val);
        }
        return ans;
    }
private:
    unordered_map<int, int> counter;
    void dfs (TreeNode* node) {
        if (node == nullptr) return;
        ++counter[node->val];
        dfs (node->left);
        dfs (node->right);
    }
};
