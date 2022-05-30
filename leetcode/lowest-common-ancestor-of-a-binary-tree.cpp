// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lca;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lca;
    }
    
    bool dfs(TreeNode* curNode, TreeNode* p, TreeNode* q) {
        
        if (curNode == nullptr) return false;
        
        bool mid = (curNode->val == p->val || curNode->val == q->val) ? true : false;
        bool left = dfs(curNode->left, p, q);
        bool right = dfs(curNode->right, p, q);
        
        if ((left && mid) || (right && mid) || (left && right)) {
            lca = curNode;
            return true;
        }
        
        return left || right || mid;
    }
};


int main() {
    return 0;
}
