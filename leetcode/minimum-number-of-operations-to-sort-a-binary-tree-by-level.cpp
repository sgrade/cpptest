// 2471. Minimum Number of Operations to Sort a Binary Tree by Level
// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 1: Hash Map
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
    int minimumOperations(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        queue<TreeNode*> q;
        q.emplace(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> vals(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                vals[i] = node->val;
                if (node->left)
                    q.emplace(node->left);
                if (node->right)
                    q.emplace(node->right);
            }
            ans += getMinSwaps(vals);
        }

        return ans;
    }
private:
    int ans = 0;
    int getMinSwaps(vector<int>& level_vals) {
        int swaps = 0;
        vector<int> target = level_vals;
        sort(target.begin(), target.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < level_vals.size(); ++i)
            pos[level_vals[i]] = i;
        for (int i = 0; i < level_vals.size(); ++i) {
            if (level_vals[i] != target[i]) {
                ++swaps;
                int cur = pos[target[i]];
                pos[level_vals[i]] = cur;
                swap(level_vals[cur], level_vals[i]);
            }
        }
        return swaps;
    }
};
