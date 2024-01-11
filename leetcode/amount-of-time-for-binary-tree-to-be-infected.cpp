// 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <bits/stdc++.h>

using namespace std;


// Improved with Editorial's Approach 2: One-Pass Depth-First Search
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
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        traverse(root);
        return ans;
    }
private:
    int start;
    int ans = 0;
    int traverse (TreeNode* node) {
        if (node == nullptr)
            return 0;
        int depth = 0;
        int left_depth = traverse(node->left);
        int right_depth = traverse(node->right);
        
        if (node->val == start) {
            ans = max(left_depth, right_depth);
            depth -= 1;
        }
        else if (left_depth >= 0 && right_depth >= 0)
            depth = max(left_depth, right_depth) + 1;
        else {
            int cur_ans = abs(left_depth) + abs(right_depth);
            ans = max(cur_ans, ans);
            depth = min(left_depth, right_depth) - 1;
        }
        return depth;
    }
};
