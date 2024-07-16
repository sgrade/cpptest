// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

#include <bits/stdc++.h>

using namespace std;


// Time Limit Exceeded
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->dest = destValue;
        adj[root->val] = {-1, -1, -1};
        bfs_get_adj (root);
        return bfs_find_path (startValue);
    }

private:
    int dest;

    // <node_val, {parent, left, right}>
    unordered_map<int, vector<int>> adj;
    void bfs_get_adj (TreeNode* node) {
        queue<TreeNode*> q;
        q.emplace(node);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->left) {
                q.emplace(node->left);
                adj[node->val][1] = node->left->val;
                adj[node->left->val] = {node->val, -1, -1};
            }
            if (node->right) {
                q.emplace(node->right);
                adj[node->val][2] = node->right->val;
                adj[node->right->val] = {node->val, -1, -1};
            }
        }
    }

    string bfs_find_path (int start) {
        vector<char> directions = {'U', 'L', 'R'};
        queue<pair<int, string>> q;
        q.emplace (start, "");
        while (q.front().first != dest) {
            auto [node, path] = q.front();
            q.pop();
            for (int i = 0; i < 3; ++i) {
                int neighbor = adj[node][i];
                if (neighbor == -1)
                    continue;
                q.emplace (neighbor, path + directions[i]);
            }
        }
        return q.front().second;
    }
};
