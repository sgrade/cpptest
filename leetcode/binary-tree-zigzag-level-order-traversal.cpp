// 103. Binary Tree Zigzag Level Order Traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    int depth;
    vector<vector<int>> output;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (output.size() <= depth) output.push_back({});
        output[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        this->depth = 0;
        output.clear();
        dfs(root, depth);
        for (int i = 1; i < output.size(); i += 2) {
            reverse(output[i].begin(), output[i].end());
        }
        return output;
    }
};


int main() {



    return 0;
}
