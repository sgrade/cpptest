// 1008. Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    int idx = 0;
    int n;
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        return dfs(numeric_limits<int>::min(), numeric_limits<int>::max(), preorder);
    }
    
    TreeNode* dfs(int lower, int upper, vector<int>& preorder) {
        if (idx == n) {
            return nullptr;
        }
        
        int val = preorder[idx];
        if (val < lower || val > upper) {
            return nullptr;
        }
        
        ++idx;
        TreeNode* cur = new TreeNode(val);
        cur -> left = dfs(lower, val, preorder);
        cur -> right = dfs(val, upper, preorder);
        
        return cur;
    }
};
