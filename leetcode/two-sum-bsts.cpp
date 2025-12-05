// 1214. Two Sum BSTs
// https://leetcode.com/problems/two-sum-bsts/

#include <vector>

using std::vector;

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

class Solution {
 public:
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    vector<int> nodes1, nodes2;
    dfs(root1, nodes1);
    dfs(root2, nodes2);

    size_t i1 = 0, i2 = nodes2.size() - 1;
    while (i1 < nodes1.size() && i2 >= 0) {
      if (nodes1[i1] + nodes2[i2] == target) {
        return true;
      } else if (nodes1[i1] + nodes2[i2] < target) {
        i1++;
      } else {
        i2--;
      }
    }
    return false;
  }

 private:
  void dfs(TreeNode* node, vector<int>& nodes) {
    if (!node) {
      return;
    }
    dfs(node->left, nodes);
    nodes.emplace_back(node->val);
    dfs(node->right, nodes);
  }
};
