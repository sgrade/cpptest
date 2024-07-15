// 2196. Create Binary Tree From Descriptions
// https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        unordered_set<int> root_candidates;
        unordered_map<int, TreeNode*> nodes;

        for (const vector<int>& description: descriptions) {
            int parent_val = description[0], child_val= description[1];
            bool is_left = description[2];

            root_candidates.erase(child_val);

            TreeNode* child_node;
            if (nodes.find(child_val) == nodes.end()) {
                child_node = new TreeNode(child_val);
                nodes[child_val] = child_node;
            }
            else
                child_node = nodes[child_val];
            
            TreeNode* parent_node;
            if (nodes.find(parent_val) == nodes.end()) {
                parent_node = new TreeNode(parent_val);
                nodes[parent_val] = parent_node;
                root_candidates.emplace(parent_val);
            }
            else
                parent_node = nodes[parent_val];
            
            if (is_left)
                parent_node->left = child_node;
            else
                parent_node->right = child_node;
        }

        int root_val = *root_candidates.begin();
        return nodes[root_val];
    }
};
