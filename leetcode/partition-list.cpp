// 86. Partition List
// https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pre_less = new ListNode;
        ListNode* pre_gre = new ListNode;
        ListNode* less = new ListNode;
        pre_less->next = less;
        ListNode* gre_or_eq = new ListNode;
        pre_gre->next = gre_or_eq;
        ListNode* nxt;
        while(head) {
            nxt = head->next;
            head->next = nullptr;
            if (head->val < x) {    
                less->next = head;
                less = less->next;
            }
            else {
                gre_or_eq->next = head;
                gre_or_eq = gre_or_eq->next;
            }
            head = nxt;
        }
        less->next = pre_gre->next->next;
        return pre_less->next->next;
    }
};
