// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = new ListNode();
        ListNode* curNode = head;
        
        while(list1 && list2) {
            
            if (list1->val < list2->val) {
                curNode->next = list1;
                curNode = list1;
                list1 = list1->next;
            }
            
            else {
                curNode->next = list2;
                curNode = list2;
                list2 = list2->next;
            }
        }
        
        if (list1) {
            curNode->next = list1;
        }
        else {
            curNode->next = list2;
        }
        
        return head->next;
    }
};
