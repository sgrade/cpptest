// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

// Based on Leetcode's Approach 2: Iterative Link Reversal.

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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *current = head, *prev = nullptr;
        
        while (--left) {
            prev = current;
            current = current->next;
            --right;
        }
        
        ListNode *left_end = prev, *right_end = current;
        
        ListNode* nxt = nullptr;
        while (right--) {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        
        if (left_end != nullptr) {
            left_end->next = prev;
        }
        else {
            head = prev;
        }
        
        right_end->next = current;
        
        return head;
    }
};
