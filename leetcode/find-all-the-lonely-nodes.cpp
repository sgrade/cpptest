// 1469. Find All The Lonely Nodes
// https://leetcode.com/problems/find-all-the-lonely-nodes/

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
    vector<int> getLonelyNodes(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                q.emplace(current->left);
                if (!current->right)
                    ans.emplace_back(current->left->val);
            }
            if (current->right) {
                q.emplace(current->right);
                if (!current->left)
                    ans.emplace_back(current->right->val);
            }
        }
        return ans;
    }
};
