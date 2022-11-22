// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/

#include <bits/stdc++.h>

using namespace std;


// Based on Leetcode's Approach 1: Insertion Sort

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *pre_ans = new ListNode();
        ListNode *current = head, *prev, *nxt;
        
        while (current) {
            prev = pre_ans;
            while (prev->next && prev->next->val <= current->val) {
                prev = prev->next;
            }

            nxt = current->next;
            current->next = prev->next;
            prev->next = current;

            current = nxt;
        }
        
        return pre_ans->next;
    }
};
