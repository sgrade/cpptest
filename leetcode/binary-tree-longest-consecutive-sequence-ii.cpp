// 549. Binary Tree Longest Consecutive Sequence II
// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

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

// Based on Editorial's Approach #2 Single traversal
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        GetLen(root);
        return max_len;
    }
private:
    int max_len = 0;
    pair<int, int> GetLen (TreeNode* node) {
        if (node == nullptr) {
            return pair<int, int>{0, 0};
        }

        int incr_len = 1, decr_len = 1;
        if (node->left != nullptr) {
            pair<int, int> left = GetLen(node->left);
            if (node->val == node->left->val - 1) {
                incr_len = left.first + 1;
            } else if (node->val == node->left->val + 1) {
                decr_len = left.second + 1;
            }
        }

        if (node->right != nullptr) {
            pair<int, int> right = GetLen(node->right);
            if (node->val == node->right->val - 1) {
                incr_len = max(incr_len, right.first + 1);
            } else if (node->val == node->right->val + 1) {
                decr_len = max(decr_len, right.second + 1);
            }
        }

        max_len = max(max_len, incr_len + decr_len - 1);
        return pair<int, int>{incr_len, decr_len};
    }
};
