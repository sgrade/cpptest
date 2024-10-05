// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#include <bits/stdc++.h>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Based on Editorial's Approach 1: Prefix Sum for Each Consecutive Sequence
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* left = front;
        while (left != nullptr) {
            int sum = 0;
            ListNode* right = left->next;
            while (right != nullptr) {
                sum += right->val;
                if (sum == 0)
                    left->next = right->next;
                right = right->next;
            }
            left = left->next;
        }
        return front->next;
    }
};
