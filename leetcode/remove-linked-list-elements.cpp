// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode();
        new_head->next = head;
        ListNode* prev = new_head;
        while (head != nullptr) {
            if (head->val != val) {
                prev = head;
                head = head->next;
                continue;
            }
            // else
            head = head->next;
            prev->next = head;
        }
        return new_head->next;
    }
};
