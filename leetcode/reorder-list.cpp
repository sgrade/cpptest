// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

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

// Based on Editorial's Approach 1: Reverse the Second Part of the List and Merge Two Sorted Lists
class Solution {
public:
    void reorderList(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ListNode* tortoise = head;
        ListNode* hare = head;

        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* cur = tortoise;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            tmp = first->next;
            first->next = second;
            first = tmp;
            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};
