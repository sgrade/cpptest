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
        ListNode* two_steps = head;
        while (two_steps) {
            two_steps = two_steps->next;
            if (!two_steps) 
                break;
            head = head->next;
            two_steps = two_steps->next;
        }
        return head;
    }
};
