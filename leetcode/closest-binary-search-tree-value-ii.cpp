// 272. Closest Binary Search Tree Value II
// https://leetcode.com/problems/closest-binary-search-tree-value-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 5: Build The Window With Deque
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->target = target, this->k = k;
        dfs(root);
        return vector<int>(q.begin(), q.end());
    }
private:
    double target;
    int k;
    deque<int> q;
    void dfs(TreeNode* node) {
        if (node == nullptr)
            return;
        dfs(node->left);
        q.emplace_back(node->val);
        if (q.size() > k) {
            if (abs(target - q.front()) <= abs(target - q.back())) {
                q.pop_back();
                return;
            }
            else
                q.pop_front();
        }
        dfs(node->right);
    }
};
