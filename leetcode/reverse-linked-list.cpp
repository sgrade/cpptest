// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>

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
    ListNode* reverseList(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
