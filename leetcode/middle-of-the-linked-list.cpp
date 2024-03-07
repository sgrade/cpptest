// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare->next && hare->next->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return hare->next ? tortoise->next : tortoise;
    }
};
