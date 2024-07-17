// 1110. Delete Nodes And Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(root, nullptr);
        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            if (to_delete_set.find(node->val) != to_delete_set.end()) {
                if (parent) {
                    if (parent->left == node)
                        parent->left = nullptr;
                    else
                        parent->right = nullptr;
                }
                q.emplace(node->right, nullptr);
                q.emplace(node->left, nullptr);
            }
            else {
                if (parent == nullptr)
                    ans.emplace_back(node);
                q.emplace(node->right, node);
                q.emplace(node->left, node);
            }
        }

        return ans;
    }
};
