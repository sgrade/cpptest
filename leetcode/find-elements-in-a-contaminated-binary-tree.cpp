// 1261. Find Elements in a Contaminated Binary Tree
// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

#include <bits/stdc++.h>

using namespace std;


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
class FindElements {
public:
    FindElements(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        queue<TreeNode*> q;
        root->val = 0;
        q.emplace(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                int x = node->val;
                values.emplace(x);
                if (node->left) {
                    node->left->val = 2 * x + 1;
                    q.emplace(node->left);
                }
                if (node->right) {
                    node->right->val = 2 * x + 2;
                    q.emplace(node->right);
                }
            }
        }
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }

private:
    unordered_set<int> values;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

