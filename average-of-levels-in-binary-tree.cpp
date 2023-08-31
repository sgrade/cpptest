// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<double> ans;

        // BFS
        queue<TreeNode*> q;
        q.emplace(root);
        
        while (!q.empty()) {
            double sum = 0.0, cnt = 0;
            queue<TreeNode*> temp;
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                ++cnt;
                if (node->left)
                    temp.emplace(node->left);
                if (node->right)
                    temp.emplace(node->right);
            }
            ans.emplace_back(sum / cnt);
            q = temp;
        }

        return ans;
    }
};
