// 2096. Step-By-Step Directions From a Binary Tree Node to Another
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        this->start = startValue;
        this->dest = destValue;
        adj[root->val] = {-1, -1, -1};
        bfs_get_adj (root);
        bfs_find_path (start);
        return trace_path(dest);
    }

private:
    int start, dest;

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

    // Idea of path_tracker is from Editorial's Approach 1: BFS + DFS
    unordered_map<int, pair<int, char>> path_tracker;
    void bfs_find_path (int start) {
        int n = adj.size();
        vector<bool> visited (n + 1);
        vector<char> directions = {'U', 'L', 'R'};
        queue<int> q;
        q.emplace (start);
        while (q.front() != dest) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (int i = 0; i < 3; ++i) {
                int neighbor = adj[node][i];
                if (neighbor == -1)
                    continue;
                if (visited[neighbor])
                    continue;
                q.emplace (neighbor);
                path_tracker.emplace(neighbor, pair<int, char>(node, directions[i]));
            }
        }
    }

    string trace_path (int& node) {
        string ans = "";
        while (node != start) {
            auto& [prev_node, direction] = path_tracker[node];
            ans += direction;
            node = prev_node;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
