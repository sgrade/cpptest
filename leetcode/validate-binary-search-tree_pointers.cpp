// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    
    bool dfs(TreeNode* cur, TreeNode* lower_limit, TreeNode* upper_limit) {
        if (cur == nullptr) return true;
        if ((lower_limit != nullptr && cur->val <= lower_limit->val) || 
            (upper_limit != nullptr && cur->val >= upper_limit->val)) {
            return false;
        }
        bool l = dfs(cur -> left, lower_limit, cur);
        bool r = dfs(cur -> right, cur, upper_limit);
        if (l && r) {
            return true;
        }
        return false;
    }
};
