// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int current_ans = numeric_limits<int>::min();
            int nodes = q.size();
            for (int i = 0; i < nodes; ++i) {
                TreeNode* node = q.front();
                q.pop();
                current_ans = max(current_ans, node->val);
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            ans.emplace_back(current_ans);
        }
        return ans;
    }
};
