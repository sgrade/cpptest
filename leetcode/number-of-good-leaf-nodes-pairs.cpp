// 1530. Number of Good Leaf Nodes Pairs
// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
    int countPairs(TreeNode* root, int distance) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (distance == 1)
            return 0;
        this->distance = distance;
        get_topology (root, nullptr);
        for (TreeNode* leaf: leafs)
            bfs (leaf);
        return ans / 2;
    }

private:
    int distance;
    int ans = 0;

    unordered_set<TreeNode*> leafs;
    // <node, <parent, left_child, right_child>>
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    void get_topology (TreeNode* node, TreeNode* parent) {
        adj[node] = vector<TreeNode*>(3);
        adj[node][0] = parent;
        if (!node->left && !node->right) {
            leafs.emplace(node);
            return;
        }
        if (node->left) {
            adj[node][1] = node->left;
            get_topology (node->left, node);
        }
        if (node->right) {
            adj[node][2] = node->right;
            get_topology (node->right, node);
        }
    }

    void bfs (TreeNode* leaf) {
        queue <TreeNode*> q;
        q.emplace(leaf);
        unordered_set<TreeNode*> visited;
        int current_distance = 1;
        while (!q.empty()) {
            int nodes = q.size();
            for (int i = 0; i < nodes; ++i) {
                TreeNode* node = q.front();
                q.pop();
                visited.emplace(node);
                for (TreeNode* neighbor: adj[node]) {
                    if (neighbor == nullptr)
                        continue;
                    if (visited.find(neighbor) != visited.end())
                        continue;
                    if (leafs.find(neighbor) != leafs.end())
                        ++ans;
                    else
                        q.emplace(neighbor);
                }
            }
            ++current_distance;
            if (current_distance > distance)
                break;
        }
    }
};
