// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach 2: Iterative Link Reversal.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right)
            return head;

        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (--left) {
            prev = cur;
            cur = cur->next;
            --right;
        }

        ListNode* prefix_end = prev;
        ListNode* mid_end = cur;

        ListNode* nxt = nullptr;
        while (right--) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        if (prefix_end != nullptr)
            prefix_end->next = prev;
        else
            head = prev;
        
        mid_end->next = cur;

        return head;
    }
};
