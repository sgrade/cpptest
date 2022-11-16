// 109. Convert Sorted List to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 3: Inorder Simulation

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *list_node = head;
        while(list_node) {
            ++n;
            list_node = list_node->next;
        }
        
        return InorderSim(head, 0, n - 1);
    }
    
private:
    TreeNode* InorderSim(ListNode* &list_node, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        
        TreeNode* left_child = InorderSim(list_node, left, mid - 1);
        
        TreeNode* ans = new TreeNode(list_node->val);
        ans->left = left_child;
        
        list_node = list_node->next;
        
        ans->right = InorderSim(list_node, mid + 1, right);
        
        return ans;
    }
    
};
