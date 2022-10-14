// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* even_pre_start = new ListNode;
        ListNode* even_current = even_pre_start;
        ListNode* current = head;

        while (current->next && current->next->next) {
            even_current->next = current->next;
            current->next = current->next->next;
            even_current->next->next = nullptr;
            even_current = even_current->next;
            current = current->next;
        }
        
        if (current->next) {
            even_current->next = current->next;
            even_current->next->next = nullptr;
        }
        
        current->next = even_pre_start->next;
        
        return head;
    }
};
