// 2265. Count Nodes Equal to Average of Subtree
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

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
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return ans;
    }
private:
    int ans = 0;
    // <sum, children>
    pair<int, int> postOrder (TreeNode* node) {
        int total_sum = node->val;
        int nodes = 1;
        if (node->left) {
            auto [sum, children] = postOrder(node->left);
            total_sum += sum;
            nodes += children;
        }
        if (node->right) {
            auto [sum, children] = postOrder(node->right);
            total_sum += sum;
            nodes += children;
        }
        int average = total_sum / nodes;
        if (node->val == average)
            ++ans;
        return {total_sum, nodes};
    }
};
