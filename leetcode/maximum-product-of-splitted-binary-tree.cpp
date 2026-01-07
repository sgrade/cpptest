// 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int maxProduct(TreeNode *root) {
    int total = GetSum(root);
    long long max_product = 0;
    for (const int sum : sums) {
      max_product =
          max(max_product, static_cast<long long>(sum) * (total - sum));
    }
    return static_cast<int>(max_product % kMod);
  }

 private:
  static constexpr int kMod = 1e9 + 7;
  vector<int> sums;
  int GetSum(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int cur = node->val + GetSum(node->left) + GetSum(node->right);
    sums.emplace_back(cur);
    return cur;
  }
};
