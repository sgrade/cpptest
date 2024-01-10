// 2385. Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <bits/stdc++.h>

using namespace std;


// WRONG ANSWER
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
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        traverse(root, false, 0);
        if (root_to_bottom != 0)
            ans = root_to_bottom + root_to_infected;
        else
            ans = root_to_infected;
        ans = max(ans, infected_to_bottom);
        return ans;
    }
private:
    int start;
    int ans = 0;
    int root_to_infected = 0, infected_to_bottom = 0, root_to_bottom = 0;
    void traverse (TreeNode* node, int depth, bool infected_in_subtree) {
        if (node->val == start) {
            infected_in_subtree = true;
            root_to_infected = depth;
            depth = 0;
        }
        if (node->left)
            traverse(node->left, depth + 1, infected_in_subtree);
        if (node->right)
            traverse(node->right, depth + 1, infected_in_subtree);
        if (!node->left && !node->right) {
            if (infected_in_subtree)
                infected_to_bottom = max(infected_to_bottom, depth);
            else
                root_to_bottom = max(root_to_bottom, depth);
        } 
    }
};
