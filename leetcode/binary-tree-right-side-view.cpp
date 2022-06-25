// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* current, const int depth) {
        if (current == nullptr) {
            return;
        }
        if (depth == ans.size()) {
            ans.push_back(current -> val);
        }        
        dfs(current -> right, depth + 1);
        dfs(current -> left, depth + 1);
    }
};
