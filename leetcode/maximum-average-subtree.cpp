// 1120. Maximum Average Subtree
// https://leetcode.com/problems/maximum-average-subtree/

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
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    double ans = 0;
    // <sum, count>
    pair<double, double> dfs(TreeNode* node) {
        pair<double, double> output;
        if (node == nullptr)
            return output;
        auto [sum_left, cnt_left] = dfs(node->left);
        auto [sum_right, cnt_right] = dfs(node->right);
        output.first = node->val + sum_left + sum_right;
        output.second = 1 + cnt_left + cnt_right;
        double current_ans = output.first / output.second;
        ans = max(ans, current_ans);
        return output;
    }
};
