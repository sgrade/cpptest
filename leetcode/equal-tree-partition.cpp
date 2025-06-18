// 663. Equal Tree Partition
// https://leetcode.com/problems/equal-tree-partition/

#include <bits/stdc++.h>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Based on Editorial's Approach #1: Depth-First Search
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int sum = getSum(root);
        int half_sum = sum / 2;
        visited.pop();

        if (sum % 2 == 0) {
            while (!visited.empty()) {
                if (visited.top() == half_sum)
                    return true;
                visited.pop();
            }
        }
        return false;
    }

private:
    stack<int> visited;
    int getSum(TreeNode* node) {
        if (node == nullptr)
            return 0;
        visited.emplace(getSum(node->left) + getSum(node->right) + node->val);
        return visited.top();
    }
};
