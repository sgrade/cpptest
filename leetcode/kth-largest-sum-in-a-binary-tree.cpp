// 2583. Kth Largest Sum in a Binary Tree
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        priority_queue<long long> sums;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            long long sum = 0;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            sums.emplace(sum);
        }
        if (sums.size() < k)
            return -1;
        for (int i = 0; i < k - 1; ++i)
            sums.pop();
        return sums.top();
    }
};
