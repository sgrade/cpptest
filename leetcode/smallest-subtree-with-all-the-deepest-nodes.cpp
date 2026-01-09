// 865. Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

#include <utility>  // for std::pair

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// Based on Editorial's Approach 2: Recursion
class Solution {
 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return GetDeepest(root).second;
  }

 private:
  std::pair<int, TreeNode*> GetDeepest(TreeNode* node) {
    if (node == nullptr) {
      return {0, nullptr};
    }
    const auto& [left_dist, left_node] = GetDeepest(node->left);
    const auto& [right_dist, right_node] = GetDeepest(node->right);
    if (left_dist > right_dist) {
      return {left_dist + 1, left_node};
    }
    if (right_dist > left_dist) {
      return {right_dist + 1, right_node};
    }
    return {left_dist + 1, node};
  }
};
