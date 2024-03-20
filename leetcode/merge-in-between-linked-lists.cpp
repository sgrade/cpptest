// 1669. Merge In Between Linked Lists
// https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = new ListNode(0);
        current->next = list1;
        ListNode* nxt;
        int i = 0;
        for (; i < a; ++i)
            current = current->next;
        ListNode* before_a = current;
        for (; i <= b; ++i )
            current = current->next;
        ListNode* after_b = current->next;
        before_a->next = list2;
        current = list2;
        while (current->next)
            current = current->next;
        current->next = after_b;
        return list1;
    }
};
